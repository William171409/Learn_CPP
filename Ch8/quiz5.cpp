// 5c) Write a function template named sub that allows the user to subtract
// two values of different types. The following program should run:

#include <iostream>

// write your sub function template here
template <class T, class U>
auto sub(T a, U b)
{
    return a - b;
}

int main()
{
    std::cout << sub(3, 2) << '\n';
    std::cout << sub(3.5, 2) << '\n';
    std::cout << sub(4, 1.5) << '\n';

    return 0;
}
