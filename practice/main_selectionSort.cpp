// My implementation selection sort
#include <iostream>
#include <iterator> // for std::size
#include "selectionSort.hpp"
int main()
{
    int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};
    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
    improved::selectionSort(array,static_cast<int>(std::size(array)));
    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';

    return 0;
}

//Using C++ stl sort()
// #include <algorithm> // for std::sort
// #include <iostream>
// #include <iterator> // for std::size

// int main()
// {
// 	int array[]{ 30, 50, 20, 10, 40 };

// 	std::sort(std::begin(array), std::end(array));

// 	for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
// 		std::cout << array[i] << ' ';

// 	std::cout << '\n';

// 	return 0;
// }