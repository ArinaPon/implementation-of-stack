#include <iostream>
#include "int_stack.h"

int main()
{
    try
    {
        levelup::IntStack stack(10);

        for(int i = 0; i < 11; ++i)
        {
            stack.push(i);
        }

        while (!stack.empty())
        {
            std::cout << stack.top() << std::endl;
            stack.pop();
        }

        int topItem = stack.top();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
