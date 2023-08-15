#include <string> // For std::string and std::getline
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin>> std::ws , name); // read a full line of text into name

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age; // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age << '\n';
    std::cout << "Your age + length of your name is: " << age+std::ssize(name) << '\n';


    return 0;
}