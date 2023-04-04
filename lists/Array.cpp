#include "Array.h"

Array::Array() : _data(nullptr), _length(0)
{
}

Array::~Array()
{
    delete[] _data;
}

// converts data from array to string
std::string Array::toString()
{
    std::string str;
    for (int i = 0; i < _length; i++)
    {
        str += std::to_string(_data[i]) + " ";
    }
    str += "\n";
    return str;
}

// adds data to front of array
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
    std::memcpy(temp + 1, _data, (_length - 1) * sizeof(int));
    temp[0] = data;
    delete[] _data;
    _data = temp;
}

// adds data to back of array
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

void Array::remove(int data)
{
    int index = -1;
    for (int i = 0; i < _length; i++)
        if (_data[i] == data)
            index = i;
    if(index == -1)
    return;

    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data, index * sizeof(int));
    std::memcpy(temp + index, _data + index + 1, (_length - index) * sizeof(int));
    delete[] _data;
    _data = temp;
}

bool Array::find(int data)
{
    for (int i = 0; i < _length; i++)
        if (_data[i] == data)
            return true;
    return false;
}