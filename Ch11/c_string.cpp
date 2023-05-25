#include <iostream>
#include <iterator> // for std::size

int main()
{
    char myString[]="string";
    const int length{ static_cast<int>(std::size(myString)) };
//  const int length{ sizeof(myString) / sizeof(myString[0]) }; // use instead if not C++17 capable
    std::cout << myString << " has " << length << " characters.\n";

    for (int index{ 0 }; index < length; ++index)
        std::cout << static_cast<char>(myString[index]) << ' ';

    std::cout << '\n';

    return 0;
}