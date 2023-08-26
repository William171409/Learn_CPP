#include <iostream>

int printdigit(int a)
{
    if (a <= 0)
        return 0;
    return (printdigit((a - a % 10) / 10) + a % 10);
}

int main()
{
    int input{93427};
    std::cout << "The sum of digits of " << input << " is equal to " << printdigit(input);

    return 0;
}