#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstring>

class Array
{
public:
    Array();
    void display();
    void addFront(int data);
    void addBack(int data);
    void addAtIndex(int index, int data);
    void removeFromFront();
    void removeFromBack();
    void removeFromIndex(int index);

private:
    int *_data;
    size_t _length;
};
#endif