#include "Heap.h"

Heap::Heap() : _data(nullptr), _length(0)
{
}

void Heap::display()
{
    for (int i = 0; i < _length; i++)
    {
        std::cout << _data[i] << " ";
    }
    std::cout << "\n";
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

void Heap::pop()
{
    if (_length == 0)
        return;
    _length--;
    int data = _data[_length];

    int i = 0, j = 1;
    while (j < _length)
    {
        if (j + 1 < _length && _data[j + 1] > _data[j])
            j++;
        if (data >= _data[j])
            break;
        _data[i] = _data[j];
        i = j;
        j = 2 * j + 1;
    }
    _data[i] = data;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    delete[] _data;
    _data = temp;
}
