#include <iostream>
#include <array>
#include <cassert>

class Stack
{
    std::array<int, 5> stack_arr{};
    int stack_arr_size{};

public:
    void reset()
    {
        stack_arr_size = 0;
    }
    void push(int a)
    {
        // std::cout<<"size = "<<stack_arr.size()<<'\n';
        assert(stack_arr_size < stack_arr.size() && "Can not push more items to the stack!");
        stack_arr[stack_arr_size++] = a;
    }

    int pop()
    {
        assert(stack_arr_size > 0 && "Can not pop empty stack!");
        return stack_arr[stack_arr_size--];
    }
    void print()
    {
        std::cout << "( ";
        for (int i{0}; i < stack_arr_size; i++)
        {
            std::cout << stack_arr[i] << ' ';
        }
        std::cout << ')';
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(1);
    stack.push(5);
    stack.push(2);

    stack.print();

    stack.pop();
    stack.pop();
    stack.pop();
    // stack.pop();
    stack.print();

    stack.push(100);
    stack.push(120);
    stack.push(1314);
    stack.push(5);
    stack.push(6);
    // stack.push(8);

    stack.print();
    stack.push(8);

    return 0;
}