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
    Heap();                                                          // constructor
    ~Heap();                                                         // destructor
    std::string toString();                                          // return a string representation of the tree
    void display();                                                  // display the tree
    void display(const std::string &prefix, int index, bool isLeft); // display the tree
    void push(int data);                                             // insert a node
    void pop(int data);                                              // delete a node
    Node *find(int data);                                            // find a node

private:
    int *_data;
    size_t _length;
};
#endif