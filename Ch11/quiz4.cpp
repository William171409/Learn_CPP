#include <iostream>
// ALERT:
//  The code appears to have a potential issue where a string literal is passed as an
//  argument to the printChar function, which takes a char * parameter. In C++, string literals
//  are constant arrays of characters, and attempting to modify them can result in
//  undefined behavior.

void printChar(const char *str)
{
    while (*str != '\0')
    {
        std::cout << *str;
        str++;
    }
    std::cout << '\n';
}
int main()
{
    printChar("hfjkawe jwle j 3 hka ");
    return 0;
}
