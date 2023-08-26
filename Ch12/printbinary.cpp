// h/t to reader Donlod for this solution
#include <iostream>

void printBinary(unsigned int n)
{
	if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
	{
		printBinary(n / 2);
	}

	std::cout << n % 2;
}

int main()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	printBinary(static_cast<unsigned int>(x));
}