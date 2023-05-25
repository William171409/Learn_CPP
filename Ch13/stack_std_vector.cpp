#include <iostream>
#include <vector>

// std::stack only provides access to the topmost element. If we want to
// print all elements, we need to copy the stack (by passing it by value)
// and pop elements until the stack is empty.
void printStack(std::vector<int> stack)
{
	std::cout << "( ";
	for (auto e : stack)
		std::cout << e << ' ';
	std::cout << ")\n";
}

int main()
{
	// Create a std::stack that holds ints.
	std::vector<int> stack;

	printStack(stack);

	stack.push_back(5);
	stack.push_back(3);
	stack.push_back(8);
	printStack(stack);

	stack.pop_back();
	stack.pop_back();
	stack.pop_back();

	printStack(stack);

	// To clear the stack, assign it an empty vector.
	stack = {};
	printStack(stack);
    stack.pop_back();


	return 0;
}