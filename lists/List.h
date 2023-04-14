#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "../utils/Structure.h"
class List : public Structure
{
public:
    virtual void addFront(int data) = 0;              // insert a node at front
    virtual void addBack(int data) = 0;               // insert a node at back
    virtual void addAtIndex(int index, int data) = 0; // insert a node at index
    virtual void removeFromFront() = 0;               // delete a node from front
    virtual void removeFromBack() = 0;                // delete a node from back
    virtual void remove(int data) = 0;                // delete a node
    virtual bool find(int data) = 0;                  // find a node
};

#endif