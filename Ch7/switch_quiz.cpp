#include <iostream>

int calculate(int x, int y, char op)
{
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            std::cerr << "calculate(): Unhandled case\n";
            return 0;
    }
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;

    std::cout << x << ' ' << op << ' ' << y << " is " << calculate(x, y, op) << '\n';

    return 0;
}