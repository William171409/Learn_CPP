#include <iostream>
#include <cstring>
#include <iterator> // for std::size

int main()
{
    char name[20]{ "Alex" }; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';
    std::cout << name << " has " << std::strlen(name) << " letters.\n";
    std::cout << name << " has " << std::size(name) << " characters in the array.\n"; // use sizeof(name) / sizeof(name[0]) if not C++17 capable

    return 0;
}