// My implementation sorting algo
#include "selectionSort.hpp"
#include "bubbleSort.hpp"
#include "insertionSort.hpp"
#include <iostream>
#include <iterator> // for std::size


int main()
{
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
    improved::bubbleSort(array, static_cast<int>(std::size(array)));
    // improved::insertionSort(array, static_cast<int>(std::size(array)));
    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';

    return 0;
}
/*
This program when compiling and linking with algo_selectionSort.cpp might cause
some bizzard errors since the original algo_selectionSort.cpp is defining a
sort of template function. Notice that template function is not considered as the definition of the
function. Whenever we call the template function, actually what's going on is the definition of the funciton
is instantiated and then the function is called. Hence, when using 'auto' keyword actually we need to include
an extra definition in the algo_selectionSort.cpp file to make sure the main() can find the definition of
selectionsort in other files

Actually, it's not suggested to use auto or template function in multiple files tasks?!!!
*/

// Using C++ stl sort()
//  #include <algorithm> // for std::sort
//  #include <iostream>
//  #include <iterator> // for std::size

// int main()
// {
// 	int array[]{ 30, 50, 20, 10, 40 };

// 	std::sort(std::begin(array), std::end(array));

// 	for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
// 		std::cout << array[i] << ' ';

// 	std::cout << '\n';

// 	return 0;
// }