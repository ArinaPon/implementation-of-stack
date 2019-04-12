#pragma once
#include <cstdint>

namespace levelup
{
class IntStack
{
public:
    explicit IntStack(size_t maxSize = 100);
    ~IntStack();

    IntStack(const IntStack& rhs);
    IntStack& operator= (const IntStack& rhs);

    void pop();
    int top() const;
    void push(int item);
    bool empty() const;

private:
    int*   _data;
    size_t _size;
    size_t _capacity;
};
}
