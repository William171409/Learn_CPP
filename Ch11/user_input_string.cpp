#include <iostream>
#include <iterator> // for std::size

int main()
{
    char name[255]{}; // declare array large enough to hold 254 characters + null terminator
    std::cout << "Enter your name: ";
    std::cin.getline(name, std::size(name));
    std::cout << "You entered: " << name << '\n';
    std::cout<<"The size of the array you have entered is "<<static_cast<int>(std::size(name))<<'\n';

    return 0;
}