#ifndef HEAP
#define HEAP

#include <vector>
class Heap 
{
public:
    Heap();
    Heap(bool is_maxHeap);
    void insert(int value); // insert value into m_elems, and keep the heap property.
    int pop(); // remove and return the root element. smallest in a min heap, largest in a max heap.
    int peek(); // return the root elemens. smallest in a min heap, largest in a max heap.
    void remove(int value); // deletes any arbitrary element from the heap.
    bool empty(); // check if the heap is empty.
    std::size_t size(); // return count of elements in the heap.
    bool is_valid_heap(); // check if m_elems is valid heap(min or max).
    void print(); // print the vector m_elems(valid max or min heap).
    void heapSort();
private:
    std::vector<int> m_elems;
    std::size_t m_size;
    bool is_maxHeap;
private: // helper functions
    void heapify_up_max_heap(int index); // for correct the max heap property when we insert new element.
    void heapify_up_min_heap(int index); // for correct the min heap property when we insert new element.
    void heapify_down_max_heap(int index); // for correct the max heap property when we delete an element.
    void heapify_down_min_heap(int index); // for correct the min heap property when we delete and element.
    int parent(int index); // return the parent node index for the given node index.
    int left_child(int index); // return the left child node index for the given node index.
    int right_child(int index); // return the right child node index for the given node index.
    bool is_valid_max_heap(); // check if m_elems is valid max heap
    bool is_valid_min_heap(); // check if m_elems is valid min heap
    void heapSort_max_heap();
    // void asc_heapSort_min_heap();
    // void desc_heapSort_max_heap();
    void heapSort_min_heap();

};
#endif //HEAP