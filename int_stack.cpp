#include "int_stack.h"
#include <stdexcept>

namespace levelup
{

void throwException(const char* message)
{
    throw std::out_of_range(message);
}

IntStack::IntStack(size_t maxSize)
    : _data(new int [maxSize])
    , _size(0)
    , _capacity(maxSize)
{}

IntStack::~IntStack()
{
    delete[] _data;
}

IntStack::IntStack(const IntStack& rhs)
{
    _data = new int [rhs._capacity];
    _size = rhs._size;
    _capacity = rhs._capacity;

    for(size_t i = 0; i < _size; ++i)
    {
        _data[i] = rhs._data[i];
    }
}

IntStack& IntStack::operator= (const IntStack& rhs)
{
    if (this != &rhs)
    {
        delete[] _data;

        _data = new int [rhs._capacity];
        _size = rhs._size;
        _capacity = rhs._capacity;

        for(size_t i = 0; i < _size; ++i)
        {
            _data[i] = rhs._data[i];
        }
    }
    return *this;
}

void IntStack::pop()
{
    if (_size == 0)
    {
        throwException("pop: _size == 0");
    }
    --_size;
}

int IntStack::top() const
{
    if (_size == 0)
    {
        throwException("top: _size == 0");
    }
    return _data[_size - 1];
}

void IntStack::push(int item)
{
    if (_size + 1 > _capacity)
    {
        throwException("stack overflow");
    }
    _data[_size++] = item;
}

bool IntStack::empty() const
{
    return _size == 0;
}

}
