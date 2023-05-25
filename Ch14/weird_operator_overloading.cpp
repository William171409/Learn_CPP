#include <iostream>
#include <string_view> // C++17

class Stupid
{
private:

public:
	void operator< (std::string_view index);
};

// It doesn't make sense to overload operator[] to print something
// but it is the easiest way to show that the function parameter can be a non-integer
void Stupid::operator<(std::string_view index)
{
	std::cout << index;
}

int main()
{
	Stupid stupid{};
	stupid<"Hello, world!\n";

	return 0;
}