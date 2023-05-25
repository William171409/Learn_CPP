#include <iostream>

int print_static(auto) // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c{0};
    return ++c;
}

int main()
{
    std::cout << print_static(1) << '\n';
    std::cout << print_static(1) << '\n';
    std::cout << print_static(1) << '\n';
    std::cout << print_static(1) << '\n';

    return 0;
}