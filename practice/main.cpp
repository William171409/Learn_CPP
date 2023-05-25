#include <iostream>
#include <iterator> // for std::size
#include "sorting_algorithms.hpp"

int main()
{
    int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};
    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';

    sorting_algorithms::selection_sort(array, static_cast<int>(std::size(array)));

    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';

    return 0;
}
