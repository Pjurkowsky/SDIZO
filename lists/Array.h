#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstring>
#include "List.h"
class Array : public List
{
public:
    Array();                              // constructor
    ~Array();                             // destructor
    std::string toString();               // return a string representation of the list
    void addFront(int data);              // insert a node at front
    void addBack(int data);               // insert a node at back
    void addAtIndex(int index, int data); // insert a node at index
    void removeFromFront();               // delete a node from front
    void removeFromBack();                // delete a node from back
    void remove(int data);                // delete a node
    bool find(int data);                  // find a node

private:
    int *_data;
    size_t _length;
};
#endif