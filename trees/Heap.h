#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include "Tree.h"
class Heap : public Tree
{
public:

    Heap();
    ~Heap();
    std::string toString();
    void push(int data);
    void pop(int data);
    Node* find(int data);

private:
    int *_data;
    size_t _length;
};
#endif