#include <iostream>
#include "DoubleLinkedList.h"
#include "Array.h"
#include "Heap.h"

int main()
{

    Heap heap;

    heap.push(6);
    heap.push(10);
    heap.push(8);
    heap.push(2);
    heap.push(16);
    heap.push(5);
    heap.push(7);

    heap.push(15);

    heap.push(3);
    heap.push(20);
    heap.display();
    heap.pop();
    heap.display();

    return 0;
}
