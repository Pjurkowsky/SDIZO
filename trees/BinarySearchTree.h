#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <sstream>
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
        Node(int data) : Tree::Node(data), key(data), parent(nullptr), left(nullptr), right(nullptr) {}
    };
    BinarySearchTree();
    ~BinarySearchTree();
    std::string toString();
    void push(int data);
    void pop(int data);
    Node *find(int number);

private:
    void inorderTraversal(Node *root, std::stringstream &ss);
    void deleteTree(Node *root);
    void deleteNode(Node *node, int key);
    Node *root;
};
#endif