#include <bitset>
#include <cstdint>
#include <iostream>
int print_decrement(int a, int e);

// int main()
// {
//     [[maybe_unused]] consteapr std::uint8_t option_viewed{ 0a01 };
//     [[maybe_unused]] consteapr std::uint8_t option_edited{ 0a02 };
//     [[maybe_unused]] consteapr std::uint8_t option_favorited{ 0a04 };
//     [[maybe_unused]] consteapr std::uint8_t option_shared{ 0a08 };
//     [[maybe_unused]] consteapr std::uint8_t option_deleted{ 0a10 };

//     std::uint8_t myArticleFlags{ option_favorited };

//     // ...

//     std::cout << std::bitset<8>{ myArticleFlags } << '\n';

//     return 0;
// }

// Question #6
// Write a program that asks the user to input a number between 0 and 255. Print this number as an 8-bit binary number (of the form #### ####).
// Don’t use any bitwise operators. Don’t use std::bitset.

int print_decrement(int a, int e)
{
    if (a >= e)
    {
        std::cout << 1;
        return a - e;
    }
    else
    {
        std::cout << 0;
        return a;
    }
}

int main()
{
    int a{-1};
    while (!((a >= 0) && (a <= 255)))
    {
        std::cout << "Enter an inter in range of [0,255]: ";
        std::cin >> a;
    }

    std::cout << "Binary form of " << a << ": ";

    a = print_decrement(a, 128);
    a = print_decrement(a, 64);
    a = print_decrement(a, 32);
    a = print_decrement(a, 16);
    std::cout << ' ';
    a = print_decrement(a, 8);
    a = print_decrement(a, 4);
    a = print_decrement(a, 2);
    a = print_decrement(a, 1);
    std::cout << '\n';

    return 0;
}