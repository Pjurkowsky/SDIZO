#ifndef REDANDBLACKTREE_H
#define REDANDBLACKTREE_H

#include <iostream>
#include <sstream>
#include <string>

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

    RedAndBlackTree();                                                      // constructor
    ~RedAndBlackTree();                                                     // destructor
    std::string toString();                                                 // return a string representation of the tree
    void display(const std::string &prefix, const Node *node, bool isLeft); // display the tree
    void display();                                                         // display the tree
    void push(int data);                                                    // insert a node
    void pop(int data);                                                     // delete a node
    Node *find(int data);                                                   // find a node

private:
    Node *findHelper(Node *node, int data);                   // find a node
    void inorderTraversal(Node *root, std::stringstream &ss); // traverse the tree in order
    void pushFix(Node *k);                                    // fix the tree after insertion
    void popFix(Node *z);                                     // fix the tree after deletion
    void leftRotate(Node *x);                                 // rotate the tree to the left
    void rightRotate(Node *x);                                // rotate the tree to the right
    Node *findSuccessor(Node *x);                             // find the successor of a node
    void transplant(Node *u, Node *v);                        // replace a node with another node
    Node *root;
    Node *nil;
};
#endif