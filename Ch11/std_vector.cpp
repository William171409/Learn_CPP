#include <array>
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::array arr{1, 2, 23, 4, 5};
    std::vector vec{1, 2, 23, 4, 5};

    std::cout << arr.size() << '\n';
    std::cout << vec.size() << '\n';

    //For both stl container, once they are initialized with a certain type. They  must pnly store
    //the data of that type.
    arr = {1}; 
    vec = {'e', 21};

    std::cout << arr.size() << '\n'; //Once std::array is initialized, its size is fixed 
    std::cout << vec.size() << '\n'; //While, std::vector can be resized by assigning.

    return 0;
}