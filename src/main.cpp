#include "../include/heap.h"
#include <iostream>
int main()
{
    Heap h(true);
    h.insert(4);
    h.insert(2);
    h.insert(1);
    h.insert(8);
    h.insert(3);
    h.heapSort();
    h.print();
    return 0;
}
