#include <iostream>

// h/t to reader Gapo for this solution
void printBinary(unsigned int x)
{
        // Termination case

	// Recurse to the next bit
    if(x>1)
	    printBinary(x / 2);

	// Print out the remainders (in reverse order)
	std::cout << x % 2;
}

int main()
{
	int x;
	std::cout << "Enter an integer: ";
	std::cin >> x;

	printBinary(static_cast<unsigned int>(x));
    std::cout<<'\n';
    return 0;
}