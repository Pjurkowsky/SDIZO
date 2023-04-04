#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "../utils/Structure.h"
class List : public Structure
{
public:
    virtual void addFront(int data) = 0;
    virtual void addBack(int data) = 0;
    virtual void addAtIndex(int index, int data) = 0;
    virtual void removeFromFront() = 0;
    virtual void removeFromBack() = 0;
    virtual void remove(int data) = 0;
    virtual bool find(int data) = 0;
};

#endif