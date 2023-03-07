#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

void DoubleLinkedList::display()
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

void DoubleLinkedList::displayReverse()
{
    Node *current = tail;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << "\n";
}

void DoubleLinkedList::addFront(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void DoubleLinkedList::addBack(int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void DoubleLinkedList::addAtIndex(int index, int data)
{
    int i = 0;
    Node *current = head;
    while (current != nullptr)
    {
        if (i == index)
        {
            Node *newNode = new Node(data);
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            return;
        }
        current = current->next;
        i++;
    }
}

void DoubleLinkedList::removeFromFront()
{
    if (head == nullptr)
        return;
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *temp = head->next;
    delete head;
    head = temp;
    head->prev = nullptr;
}

void DoubleLinkedList::removeFromBack()
{
    if (head == nullptr)
        return;
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void DoubleLinkedList::removeFromIndex(int index)
{
    int i = 0;
    Node *current = head;
    while (current != nullptr)
    {
        if (i == index)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }
        current = current->next;
        i++;
    }
}

DoubleLinkedList::Node::Node(int data) : data(data), next(nullptr), prev(nullptr) {}
