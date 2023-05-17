#include "Array.h"

Array::Array() : _data(nullptr), _length(0)
{
}

Array::~Array()
{
    delete[] _data; // delete the array
}

// converts data from array to string
std::string Array::toString()
{
    std::string str;
    for (int i = 0; i < _length; i++)
        str += std::to_string(_data[i]) + " ";
    str += "\n";
    return str;
}

// adds data to front of array
void Array::addFront(int data)
{
    if (_length == 0) // if array is empty add first element
    {
        _data = new int;
        *_data = data;
        _length++;
        return;
    }
    // otherwise add element to array by copying array to temp array and adding element to front
    _length++;
    int *temp = new int[_length];
    std::memcpy(temp + 1, _data, (_length - 1) * sizeof(int));
    temp[0] = data;
    // delete old array and set new array to temp array
    delete[] _data;
    _data = temp;
}

// adds data to back of array
void Array::addBack(int data)
{
    if (_length == 0) // if array is empty add first element
    {
        _data = new int;
        *_data = data;
        _length++;
        return;
    }
    // otherwise add element to array by copying array to temp array and adding element to back
    _length++;
    int *temp = new int[_length];
    std::memcpy(temp, _data, (_length - 1) * sizeof(int));
    temp[_length - 1] = data;
    // delete old array and set new array to temp array
    delete[] _data;
    _data = temp;
}
// adds data to array at index
void Array::addAtIndex(int index, int data)
{
    if (_length == 0)
    {
        addFront(data); // if array is empty add first element}
        return;
    }
    if (_length < index) // if index is out of bounds return
        return;
    // otherwise add element to array by copying array to temp array and adding element to index

    _length++;
    int *temp = new int[_length];
    std::memcpy(temp, _data, index * sizeof(int));
    std::memcpy(temp + index + 1, _data + index, (_length - index - 1) * sizeof(int));
    temp[index] = data;
    // delete old array and set new array to temp array
    delete[] _data;
    _data = temp;
}
// removes data from front of array
void Array::removeFromFront()
{
    if (_length == 0) // if array is empty return
        return;
    // otherwise remove element from array by copying array to temp array and removing element from front
    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data + 1, _length * sizeof(int));
    // delete old array and set new array to temp array
    delete[] _data;
    _data = temp;
}
// removes data from back of array
void Array::removeFromBack()
{
    if (_length == 0) // if array is empty return
        return;
    // otherwise remove element from array by copying array to temp array and removing element from back
    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data, _length * sizeof(int));
    // delete old array and set new array to temp array
    delete[] _data;
    _data = temp;
}
// removes data from array
void Array::remove(int data)
{ // find index of data
    int index = -1;
    for (int i = 0; i < _length; i++)
        if (_data[i] == data) // if data is found set index to i and break
        {
            index = i;
            break;
        }
    if (index == -1) // if data is not found return
        return;

    // otherwise remove element from array by copying array to temp array and removing element from index
    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data, index * sizeof(int));
    std::memcpy(temp + index, _data + index + 1, (_length - index) * sizeof(int));
    // delete old array and set new array to temp array
    delete[] _data;
    _data = temp;
}

void Array::removeFromIndex(int index)
{
    if (_length == 0)
        return;
    if (_length <= index)
        return;
    if (index < 0)
        return;

    _length--;
    int *temp = new int[_length];
    std::memcpy(temp, _data, index * sizeof(int));
    std::memcpy(temp + index, _data + index + 1, (_length - index) * sizeof(int));

    delete[] _data;
    _data = temp;
}

// returns data at index
bool Array::find(int data)
{
    for (int i = 0; i < _length; i++)
        if (_data[i] == data) // if data is found return true
            return true;
    return false; // if data is not found return false
}