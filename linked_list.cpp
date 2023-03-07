#include <iostream>

template <class T>
class LinkedList
{
public:
    LinkedList();
    void displayList();
    void addToHead(T data);
    void addToTail(T data);
    void addAtIndex(int index, T data);
    bool find(T data);
    void removeFromHead();
    void removeFromTail();

private:
    struct Node
    {
        T data;
        Node *next;

        Node(T data, Node *next) : data(data), next(next) {}
    };
    Node *head;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <class T>
void LinkedList<T>::displayList()
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template <class T>
void LinkedList<T>::addToHead(T data)
{
    Node *newNode = new Node(data, head);
    head = newNode;
}

template <class T>
void LinkedList<T>::addToTail(T data)
{
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(data, nullptr);
}
template <class T>
void LinkedList<T>::addAtIndex(int index, T data)
{
    Node *current = head;
    int i = 0;
    while (current != nullptr)
    {
        if (index == i + 1)
        {
            current->next = new Node(data, current->next);
            return;
        }
        i++;
        current = current->next;
    }
}

template <class T>
void LinkedList<T>::removeFromHead()
{
    Node *current = head->next;
    delete head;
    head = current;
}

template <class T>
void LinkedList<T>::removeFromTail()
{
    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

template <class T>
bool LinkedList<T>::find(T data)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
