// My implementation selection sort improved version
#include <iostream>
#include <iterator> // for std::size
#include <utility>
#include "selectionSort.hpp"

namespace improved
{       template <typename T>
        void selectionSort(T p, int size_array)
        {

            for (int index{0}; index < size_array - 1; index++)
            {
                int temp_index{index};
                for (int sub_index = {index + 1}; sub_index < size_array; sub_index++)
                {
                    if (p[sub_index] < p[temp_index])
                    {
                        temp_index = sub_index;
                    }
                }
                std::swap(p[index], p[temp_index]);
            }
        } 
        template void selectionSort(int* p, int size_array);
} // namespace improved
