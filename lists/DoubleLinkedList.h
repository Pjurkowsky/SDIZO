#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <cstring>
#include "List.h"
class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();                   // constructor
    ~DoubleLinkedList();                  // destructor
    std::string toString();               // return a string representation of the list
    void displayReverse();                // display the list in reverse
    void addFront(int data);              // insert a node at front
    void addBack(int data);               // insert a node at back
    void addAtIndex(int index, int data); // insert a node at index
    void removeFromFront();               // delete a node from front
    void removeFromBack();                // delete a node from back
    void remove(int data);                // delete a node
    bool find(int number);                // find a node

private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int data);
    };
    Node *head;
    Node *tail;
};
#endif