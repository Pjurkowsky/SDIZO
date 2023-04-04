#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <cstring>
#include "List.h"
class DoubleLinkedList : public List
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    std::string toString();
    void displayReverse();
    void addFront(int data);
    void addBack(int data);
    void addAtIndex(int index, int data);
    void removeFromFront();
    void removeFromBack();
    void remove(int data);
    bool find(int number);

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