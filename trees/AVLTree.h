#ifndef AVLTree_H
#define AVLTree_H

#include <iostream>
#include <sstream>
#include "Tree.h"
class AVLTree : public Tree
{
public:
    struct Node : public Tree::Node
    {
        int key;
        int height;
        Node *parent;
        Node *left;
        Node *right;
        Node(int data) : Tree::Node(data), key(data), height(0), parent(nullptr), left(nullptr), right(nullptr){};
    };

    AVLTree();                                                              // constructor
    ~AVLTree();                                                             // destructor
    std::string toString();                                                 // return a string representation of the tree
    void display(const std::string &prefix, const Node *node, bool isLeft); // display the tree
    void display();                                                         // display the tree
    void push(int data);                                                    // insert a node
    void pop(int data);                                                     // delete a node
    Node *find(int data);                                                   // find a node

private:
    void inorderTraversal(Node *root, std::stringstream &ss); // traverse the tree in order
    void leftRotate(Node *x);                                 // rotate the tree to the left
    void rightRotate(Node *x);                                // rotate the tree to the right
    Node *root;
};
#endif