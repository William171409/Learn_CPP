#include <iostream>
#include <iterator>
#include <cassert>

class Stack
{
    int arr[10];
    int a_size{0};

public:
    void print()
    {
        std::cout << '(';
        int index{};
        for (auto i : arr)
        {
            if (index < a_size)
                std::cout << i << ' ';
            index++;
        }
        std::cout << ')' << std::endl;
    }
    bool push(int num)
    {
        if ((a_size) == std::size(arr))
            return false;
        else
            arr[a_size++] = num;
        return true;
    }
    int pop()
    {
        assert(a_size > 0 && "Can not pop empty stack");
        a_size--;
        return arr[a_size + 1];
    }
    void reset()
    {
        a_size = 0;
    }
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.push(100);
    stack.print();

    stack.push(8); // stack overflow!!!! FULL
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.print();

    stack.pop();


    return 0;
}