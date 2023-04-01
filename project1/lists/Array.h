#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstring>
#include "List.h"
class Array : public List
{
public:
    Array();
    ~Array();
    std::string toString();
    void addFront(int data);
    void addBack(int data);
    void addAtIndex(int index, int data);
    void removeFromFront();
    void removeFromBack();
    void removeFromIndex(int index);
    bool find(int number);

private:
    int *_data;
    size_t _length;
};
#endif