#include "Heap.h"

Heap::Heap() : _data(nullptr), _length(0)
{
}

Heap::~Heap()
{
    delete[] _data; // delete the tree
}

// return a string representation of the tree
std::string Heap::toString()
{
    std::string str;
    for (int i = 0; i < _length; i++)
        str += std::to_string(_data[i]) + " ";
    str += "\n";
    return str;
}

// display the tree
void Heap::display()
{
    display("", 0, false);
}

// display the tree
void Heap::display(const std::string &prefix, int index, bool isLeft)
{
    if (index < _length)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << _data[index] << std::endl;
        display(prefix + (isLeft ? "│   " : "    "), 2 * index + 1, true);
        display(prefix + (isLeft ? "│   " : "    "), 2 * index + 2, false);
    }
}

// add data to the tree
void Heap::push(int data)
{
    if (_length == 0) // if tree is empty add first element
    {
        _data = new int;
        *_data = data;
        _length++;
        return;
    }
    // otherwise add element to tree by copying tree to temp tree and adding element
    _length++;
    int *tempArray = new int[_length];
    std::memcpy(tempArray, _data, _length * sizeof(int));

    int child = _length - 1;
    int parent = (child - 1) / 2;

    while (child > 0 && data > tempArray[parent]) // while child is not root and child is greater than parent
    {
        tempArray[child] = tempArray[parent]; // swap child and parent
        child = parent;                       // set child to parent
        parent = (child - 1) / 2;             // set parent to parent of child
    }
    tempArray[child] = data;
    // delete old tree and set new tree to temp tree
    delete[] _data;
    _data = tempArray;
}

// delete a node
void Heap::pop(int data)
{
    if (_length == 0) // if tree is empty return
        return;
    // otherwise delete element from tree by copying tree to temp tree and deleting element
    _length--;
    int tempData = _data[_length];

    int i = 0, j = 1;
    while (j < _length) // while child is not leaf
    {
        if (j + 1 < _length && _data[j + 1] > _data[j]) // if right child is greater than left child
            j++;
        if (tempData >= _data[j]) // if parent is greater than child
            break;
        _data[i] = _data[j]; // swap parent and child
        i = j;               // set parent to child
        j = 2 * j + 1;       // set child to left child of parent
    }
    _data[i] = tempData;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    // delete old tree and set new tree to temp tree
    delete[] _data;
    _data = temp;
}

// find a node
Tree::Node *Heap::find(int number)
{
    for (int i = 0; i < _length; i++) // loop through tree
        if (_data[i] == number)       // if number is found return node
            return new Node(_data[i]);
    return nullptr; // otherwise return null
}
