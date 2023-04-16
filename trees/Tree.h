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
    virtual void display() = 0;       // display the tree
    virtual void push(int data) = 0;  // insert a node
    virtual void pop(int data) = 0;   // delete a node
    virtual Node *find(int data) = 0; // find a node
};

#endif