#include "Array.h"

Array::Array() : _data(nullptr), _length(0)
{
}

void Array::display()
{
    for (int i = 0; i < _length; i++)
    {
        std::cout << _data[i] << " ";
    }
    std::cout << "\n";
}

void Array::addFront(int data)
{

    if (_length == 0)
    {
        _data = new int;
        *_data = data;
        _length++;
        return;
    }
    _length++;
    int *temp = new int[_length];
    std::memcpy(temp + 1, _data, _length * sizeof(int));
    temp[0] = data;
    delete[] _data;
    _data = temp;
}

void Array::addBack(int data)
{
    if (_length == 0)
    {
        _data = new int;
        *_data = data;
        _length++;
        return;
    }
    _length++;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    temp[_length - 1] = data;
    delete[] _data;
    _data = temp;
}

void Array::addAtIndex(int index, int data)
{
    if (_length < index)
        return;
    _length++;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    std::memcpy(temp + index + 1, temp + index, (_length - index) * sizeof(int));
    temp[index] = data;
    delete[] _data;
    _data = temp;
}

void Array::removeFromFront()
{
    if (_length == 0)
        return;
    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data + 1, _length * sizeof(int));
    delete[] _data;
    _data = temp;
}

void Array::removeFromBack()
{
    if (_length == 0)
        return;
    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    delete[] _data;
    _data = temp;
}

void Array::removeFromIndex(int index)
{
    if (_length == 0)
        return;
    if (_length <= index)
        return;
    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data, index * sizeof(int));
    std::memcpy(temp + index, _data + index + 1, (_length - index) * sizeof(int));
    delete[] _data;
    _data = temp;
}
