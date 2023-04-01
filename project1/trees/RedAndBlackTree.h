#ifndef REDANDBLACKTREE_H
#define REDANDBLACKTREE_H

#include <iostream>

#include "Tree.h"
class RedAndBlackTree : public Tree
{
public:
    struct Node : public Tree::Node
    {
        int key;
        char color;
        Node *parent;
        Node *left;
        Node *right;
        Node(int data) : Tree::Node(data), color('B'), parent(nullptr), left(nullptr), right(nullptr){};
    };

    RedAndBlackTree();
    std::string toString();
    void push(int data);
    void pop(int data);
    Node *find(int number) override;

    Node *root;
};
#endif