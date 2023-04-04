#ifndef REDANDBLACKTREE_H
#define REDANDBLACKTREE_H

#include <iostream>
#include <sstream>
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
        Node(int data) : Tree::Node(data), key(data), color('B'), parent(nullptr), left(nullptr), right(nullptr){};
    };

    RedAndBlackTree();
    std::string toString();
    void push(int data);
    void pop(int data);
    Node *find(int data);

private:
    void inorderTraversal(Node *root, std::stringstream &ss);
    void pushFix(Node *k);
    void popFix(Node *z);
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    Node *findSuccessor(Node *x);
    Node *root;
    Node *nil;
};
#endif