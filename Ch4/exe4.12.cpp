#include <iostream>
// Explicit conversion
// char getChar()
// {
//     std::cout << "Enter a single character: ";
//     char tempChar;
//     std::cin >> tempChar;
//     return tempChar;
// }

// int main()
// {
//     char ch{getChar()};
//     std::cout << "You entered " << ch << ", which has ASCII code " << static_cast<int>(ch) << '\n';

//     return 0;
// }

// Imlicit conversion

int charAsInt(char c)
{
	return c;
}

int main()
{
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;

	std::cout << "You entered '" << c << "', which has ASCII code " << charAsInt(c) << ".\n";

	return 0;
}