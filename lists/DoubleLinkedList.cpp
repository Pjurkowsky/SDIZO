#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

DoubleLinkedList::~DoubleLinkedList()
{
    Node *next;
    while (head != nullptr) // delete all nodes
    {
        next = head->next;
        delete head;
        head = next;
    }
}

// converts data from list to string
std::string DoubleLinkedList::toString()
{
    Node *current = head;
    std::string str;
    while (current != nullptr)
    {
        str += std::to_string(current->data) + " ";
        current = current->next;
    }
    str += "\n";
    return str;
}

// display the list in reverse order
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

// adds data to front of list
void DoubleLinkedList::addFront(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr) // if list is empty add new node and return
    {
        head = newNode;
        tail = newNode;
        return;
    }
    // otherwise add node to front
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// adds data to back of list
void DoubleLinkedList::addBack(int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr) // if list is empty add new node and return
    {
        head = newNode;
        tail = newNode;
        return;
    }
    // otherwise add node to back
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void DoubleLinkedList::addAtIndex(int index, int data)
{
    int i = 0;
    Node *current = head;
    while (current != nullptr) // iterate through list until index is reached
    {
        if (i == index) // if index is reached add node
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

// removes first element from list
void DoubleLinkedList::removeFromFront()
{
    if (head == nullptr) // if list is empty return
        return;
    if (head == tail) // if list has one element delete it and return
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    // otherwise delete head and set new head to next node
    Node *temp = head->next;
    delete head;
    head = temp;
    head->prev = nullptr;
}

// removes last element from list
void DoubleLinkedList::removeFromBack()
{
    if (head == nullptr) // if list is empty return
        return;
    if (head == tail) // if list has one element delete it and return
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // otherwise delete tail and set new tail to previous node
    Node *temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void DoubleLinkedList::removeFromIndex(int index)
{
    int i = 0;
    Node *current = head;
    while (current != nullptr) // iterate through list until index is reached
    {
        if (i == index) // if index is reached add node
        {
            if (current->prev != nullptr) // if node is not head
                current->prev->next = current->next;
            if (current->next != nullptr) // if node is not tail
                current->next->prev = current->prev;
            if (current == head) // if node is head
                head = current->next;
            if (current == tail) // if node is tail
                tail = current->prev;

            delete current;
            return;
        }
        current = current->next;
        i++;
    }
}

// removes element at index from list
void DoubleLinkedList::remove(int data)
{
    Node *current = head;
    while (current != nullptr) // iterate through list until index is reached
    {
        if (current->data == data)
        {
            if (current->prev != nullptr) // if node is not head
                current->prev->next = current->next;
            if (current->next != nullptr) // if node is not tail
                current->next->prev = current->prev;
            if (current == head) // if node is head
                head = current->next;
            if (current == tail) // if node is tail
                tail = current->prev;

            delete current;
            return;
        }
        current = current->next;
    }
}

// find a node
bool DoubleLinkedList::find(int number)
{
    Node *current = head;
    while (current != nullptr) // iterate through list until index is reached
    {
        if (current->data == number) // if index is reached return true
            return true;
        current = current->next;
    }
    return false; // if index is not reached return false
}

DoubleLinkedList::Node::Node(int data) : data(data), next(nullptr), prev(nullptr) {}
