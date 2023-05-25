#include <iostream>
#include <limits>
#include <iterator> // for std::size
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main()
{
    constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};
    int num{};
    int num_index{};

    while (true)
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> num;
        if (!std::cin || (num < 1 || num > 9))
        {
            std::cin.clear();
            ignoreLine();
            std::cout << "Oops, please enter a valid integer!" << std::endl;
            continue;
        }
        else
        {
            ignoreLine();
            break;
        }
    }
    std::cout << num << '\n';
    for (int index{0}; index < static_cast<int>(std::size(array)); ++index)
    {
        std::cout << array[index] << ' ';
        if (array[index] == num)
            num_index = index;
    }

    std::cout << '\n';
    std::cout << "The number " << num << " has index " << num_index << '\n';

    return 0;
}