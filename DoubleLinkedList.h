#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>

class DoubleLinkedList
{
public:
    DoubleLinkedList();
    void display();
    void displayReverse();
    void addFront(int data);
    void addBack(int data);
    void addAtIndex(int index, int data);
    void removeFromFront();
    void removeFromBack();
    void removeFromIndex(int index);


private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int data);
    };
    Node* head;
    Node* tail;
};
#endif