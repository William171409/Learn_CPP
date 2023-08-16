#include <bitset>
#include <cstdint>
#include <iostream>
// int print_decrement(int a, int e);

// // Question #6
// // Write a program that asks the user to input a number between 0 and 255. Print this number as an 8-bit binary number (of the form #### ####).
// // Don’t use any bitwise operators. Don’t use std::bitset.

// int print_decrement(int a, int e)
// {
//     if (a >= e)
//     {
//         std::cout << 1;
//         return a - e;
//     }
//     else
//     {
//         std::cout << 0;
//         return a;
//     }

// }
int getInt()
{

    std::cout<<"Enter an integer in the range of [0,255]: ";
    int x{};
    std::cin>>x;
    while (!((x >= 0) && (x <= 255)))
    {
        std::cout << "Please enter an inter in range of [0,255]: ";
        std::cin >> x;
    }

    return x;
}

// int main()
// {
//     int a{getInt()};

//     std::cout << "Binary form of " << a << ": ";

//     a = print_decrement(a, 128);
//     a = print_decrement(a, 64);
//     a = print_decrement(a, 32);
//     a = print_decrement(a, 16);
//     std::cout << ' ';
//     a = print_decrement(a, 8);
//     a = print_decrement(a, 4);
//     a = print_decrement(a, 2);
//     a = print_decrement(a, 1);
//     std::cout << '\n';

//     return 0;
// }

void printBinary(int deciamlNum)
{
    if(deciamlNum>0)
    {
        std::cout<<(deciamlNum%2);
        return printBinary(deciamlNum/2);
    }
}

int main()
{
    int a{getInt()};
    std::cout << "Binary form of " << a << ": ";
    printBinary(a);
    std::cout << '\n';
    return 0;
}