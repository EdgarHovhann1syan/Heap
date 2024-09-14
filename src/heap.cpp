#include "../include/heap.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
Heap::Heap() : is_maxHeap(true), m_size(0) {}

Heap::Heap(bool is_maxHeap) : is_maxHeap(is_maxHeap), m_size(0) {}

void Heap::insert(int value) 
{
    this->m_elems.push_back(value);
    ++this->m_size;
    this->is_maxHeap ? this->heapify_up_max_heap(this->m_size - 1) : this->heapify_up_min_heap(this->m_size - 1);
}

int Heap::pop()
{
    if(this->empty()) throw std::out_of_range("Heap is empty");

    int root_value = this->m_elems[0];
    this->m_elems[0] = this->m_elems[m_size - 1];
    m_elems.pop_back();
    --m_size;
    if (m_size > 0) {  // Check if the heap is not empty
        this->is_maxHeap ? this->heapify_down_max_heap(0) : this->heapify_down_min_heap(0);
    }
    return root_value;

}

int Heap::peek()
{
    if(this->empty()) throw std::out_of_range("Heap is empty");
    return this->m_elems[0];
}

bool Heap::empty()
{
    return m_size == 0;
}

std::size_t Heap::size()
{
    return m_size;
}

void Heap::print()
{
    for(int elem : m_elems)
    {
        std::cout << elem << "  ";
    }
    std::cout << std::endl;
}

void Heap::heapify_up_max_heap(int index)
{
    if(index > 0)
    {
        int parent_index = this->parent(index);
        if(this->m_elems[index] > this->m_elems[parent_index])
        {
            std::swap(this->m_elems[index], this->m_elems[parent_index]);
        }
        this->heapify_up_max_heap(parent_index);
    }
}

void Heap::heapify_up_min_heap(int index)
{
    if(index > 0)
    {
        int parent_index = this->parent(index);
        if(this->m_elems[index] < this->m_elems[parent_index])
        {
            std::swap(this->m_elems[index], this->m_elems[parent_index]);
        }
        this->heapify_up_min_heap(parent_index);
    }
}

void Heap::heapify_down_max_heap(int index)
{
    int left_child_index = this->left_child(index);
    int right_child_index = this->right_child(index);
    if(left_child_index < m_size)
    {
        int largest = index;
        if(this->m_elems[left_child_index] > this->m_elems[largest])
        {
            largest = left_child_index;
        }
        
        if(right_child_index < m_size && this->m_elems[right_child_index] > this->m_elems[largest])
        {
            largest = right_child_index;
        }

        if(largest != index)
        {
            std::swap(this->m_elems[largest], this->m_elems[index]);
            this->heapify_down_max_heap(largest);
        }
    }
}

void Heap::remove(int value)
{
    if(this->empty()) throw std::out_of_range("Heap is Empty");

    auto pos = std::find(this->m_elems.begin(), this->m_elems.end(), value);
    if(pos == this->m_elems.end())
    {
        throw std::invalid_argument("Element not found in the heap");
    }

    int removeIndex = std::distance(this->m_elems.begin(), pos);
    this->m_elems[removeIndex] = this->m_elems[this->m_size - 1];
    this->m_elems.pop_back();
    --this->m_size;
    this->is_maxHeap ? this->heapify_down_max_heap(removeIndex) : this->heapify_down_min_heap(removeIndex);
}

void Heap::heapSort()
{
    int n = this->m_size;
    for(int i = n - 1; i > 0; --i)
    {
        std::swap(this->m_elems[0], this->m_elems[i]);
        --this->m_size;
        this->is_maxHeap ? this->heapify_down_max_heap(0) : this->heapify_down_min_heap(0);
    }
    this->m_size = n;
}
bool Heap::is_valid_heap()
{
    return this->is_maxHeap ? this->is_valid_max_heap() : this->is_valid_min_heap();
}


bool Heap::is_valid_max_heap()
{
    int left_child_index = 0;
    int right_child_index = 0;
    for(int i = 0; i < this->m_size; ++i)
    {
        left_child_index = this->left_child(i);
        right_child_index = this->right_child(i);
        if(left_child_index < this->m_size && this->m_elems[left_child_index] > this->m_elems[i])
        {
            return false;
        }
        if(right_child_index < this->m_size && this->m_elems[right_child_index] > this->m_elems[i])
        {
            return false;
        }
    }
    return true;
}

bool Heap::is_valid_min_heap()
{
    int left_child_index = 0;
    int right_child_index = 0;
    for(int i = 0; i < this->m_size; ++i)
    {
        left_child_index = this->left_child(i);
        right_child_index = this->right_child(i);
        
        if(left_child_index < this->m_size && this->m_elems[left_child_index] < this->m_elems[i])
        {
            return false;
        }
        if(right_child_index < this->m_size && this->m_elems[right_child_index] < this->m_elems[i])
        {
            return false;
        }
    }
    return true;
}
void Heap::heapify_down_min_heap(int index)
{
    int left_child_index = this->left_child(index);
    int right_child_index = this->right_child(index);
    if(left_child_index < m_size)
    {
        int smallest = index;
        if(this->m_elems[left_child_index] < this->m_elems[smallest])
        {
            smallest = left_child_index;
        }

        if(right_child_index < m_size && this->m_elems[right_child_index] < this->m_elems[smallest])
        {
            smallest = right_child_index;
        }

        if(smallest != index)
        {
            std::swap(this->m_elems[smallest], this->m_elems[index]);
            this->heapify_down_min_heap(smallest);
        }
    }
}

int Heap::parent(int index)
{
    return (index - 1) / 2;
}

int Heap::left_child(int index)
{
    return (2 * index) + 1;
}

int Heap::right_child(int index)
{
    return (2 * index) + 2;
}
