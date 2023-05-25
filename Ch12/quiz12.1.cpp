#include <iostream>
#include <functional>
#include <limits>
#include <cassert>
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int getInt()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a int value: ";
        int x{};
        std::cin >> x;

        // Check for failed extraction
        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();     // and remove the bad input
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input
            return x;
        }
    }
}
char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter an operator(+-*/): ";
        char x{};
        std::cin >> x;
        ignoreLine();
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return x;
        else
            std::cout << "Enter an valid algebraic operator!\n";
    }
}
int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

// using ArithmaticFunction = std::function<int(int, int)>;
using ArithmaticFunction = int(*)(int,int);

ArithmaticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return divide;
    default:
        // std::cout<<"Invaid operator!\n";
        assert(0 &&"Invaid operator!\n"); //????????????????????/
        break;
    }
}
int main()
{
    int a{getInt()};
    int b{getInt()};
    char operation{getOperator()};
    std::cout << a << ' ' << operation << ' ' << b << '=' << getArithmeticFunction(operation)(a, b) <<'\n';

    return 0;
}
