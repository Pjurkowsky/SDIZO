#include "Heap.h"

Heap::Heap() : _data(nullptr), _length(0)
{
}

Heap::~Heap()
{
     delete[] _data;
}

std::string Heap::toString()
{
    std::string str;
    for (int i = 0; i < _length; i++)
    {
        str += std::to_string(_data[i]) + " ";
    }
    str += "\n";
    return str;
}

void Heap::push(int data)
{
    if (_length == 0)
    {
        _data = new int;
        *_data = data;
        _length++;
        return;
    }
    _length++;
    int *tempArray = new int[_length];
    std::memcpy(tempArray, _data, _length * sizeof(int));

    int child = _length - 1;
    int parent = (child - 1) / 2;

    while (child > 0 && data > tempArray[parent])
    {
        tempArray[child] = tempArray[parent];
        child = parent;
        parent = (child - 1) / 2;
    }
    tempArray[child] = data;
    delete[] _data;
    _data = tempArray;
}

void Heap::pop(int data)
{
    if (_length == 0)
        return;
    _length--;
    int tempData = _data[_length];

    int i = 0, j = 1;
    while (j < _length)
    {
        if (j + 1 < _length && _data[j + 1] > _data[j])
            j++;
        if (tempData >= _data[j])
            break;
        _data[i] = _data[j];
        i = j;
        j = 2 * j + 1;
    }
    _data[i] = tempData;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    delete[] _data;
    _data = temp;
}

Tree::Node *Heap::find(int number)
{
    for (int i = 0; i < _length; i++)
        if (_data[i] == number)
            return new Node(_data[i]);
    return nullptr;
}
