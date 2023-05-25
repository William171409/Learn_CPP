#include <array>
#include <cstddef>
#include <iostream>

// printArray is a template function
template <typename T, std::size_t size> // parameterize the element type and size
void printArray(const std::array<T, size> &myArray)
{
    for (auto element : myArray)
        std::cout << element << ' ';
    std::cout << '\n';
}

int main()
{
    std::array myArray5{9.0, 7.2, 5.4, 3.6, 1.8};
    printArray(myArray5);

    std::array myArray7{9.0, 7.2, 5.4, 3.6, 1.8, 1.2, 0.7};
    printArray(myArray7);

    return 0;
}