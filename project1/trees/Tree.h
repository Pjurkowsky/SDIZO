#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "../utils/Structure.h"

class Tree : public Structure
{
public:
    struct Node
    {
        int key;
        Node(int data) : key(data){};
    };

    virtual void push(int data) = 0;
    virtual void pop(int data) = 0;
    virtual Node* find(int data) = 0;
};

#endif