#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>
class Heap
{
public:
    Heap();
    void display();
    void push(int data);
    void pop();

private:
    int *_data;
    size_t _length;
};
#endif