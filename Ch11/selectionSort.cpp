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

    // if (sizeof(array) / sizeof(array[0]) < 1)
    //     return 0;
    // else
    // {
    //     int temp{};
    //     int size_array{sizeof(array) / sizeof(array[0])};
    //     for (int index{0}; index < size_array-1; index++)
    //     {
    //         // int max{array[index]};
    //         for (int sub_index = {index + 1}; sub_index < size_array; sub_index++)
    //         {
    //             if (array[sub_index] < array[index])
    //             {
    //                 temp = array[sub_index];
    //                 array[sub_index] = array[index];
    //                 array[index] = temp;
    //             }
    //         }
    //     }
    // }
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