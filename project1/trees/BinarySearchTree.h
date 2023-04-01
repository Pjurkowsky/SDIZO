#ifndef REDANDBLACKTREE_H
#define REDANDBLACKTREE_H

#include <iostream>
#include "Tree.h"
class BinarySearchTree : public Tree
{
public:
    struct Node : public Tree::Node
    {
        int key;
        Node *parent;
        Node *left;
        Node *right;
        Node(int data): Tree::Node(data), parent(nullptr), left(nullptr), right(nullptr){}
    };
    BinarySearchTree();
    std::string toString();
    void push(int data);
    void pop(int data);
    Node *find(int number);

private:
    Node *root;
};
#endif