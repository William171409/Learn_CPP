#include <vector>
#include <iostream>

// Vectors may allocate extra capacity
// When a vector is resized, the vector may allocate more capacity than is needed. 
// This is done to provide some “breathing room” for additional elements, 
// to minimize the number of resize operations needed. Let’s take a look at this:
int main()
{
	std::vector v{ 0, 1, 2, 3, 4 };
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	v.push_back(5); // add another element will create extra capacity
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	v[11] = 5 ;   //This is actually an undefined beahaviour!
    std::cout <<v[11] << "\n" ;
    std::cout << "size" << v.size() << "  cap :" << v.capacity() << "\n" ;

	v.resize(20);
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';
	
	v.reserve(50);
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	return 0;
}