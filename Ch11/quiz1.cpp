// Pretend you’re writing a game where the player can hold 3 types of items:
// health potions, torches, and arrows. Create an enum to identify the different
// types of items, and an std::array to store the number of each item the player
// is carrying (the enumerators are used as indexes of the array).
// The player should start with 2 health potions, 5 torches, and 10 arrows.
// Write a function called countTotalItems() that returns how many items the player
// has in total. Have your main() function print the output of countTotalItems()
// as well as the number of torches.

#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <numeric> // std::reduce

enum Item
{
    hp,
    torch,
    arrow,
    Maxlength,
};

int countTotalItems(std::array<int, Maxlength> arr)
{
    return std::reduce(arr.begin(), arr.end());
}
int main()
{
    std::array<int, Maxlength> arr{2, 5, 10};
    std::cout << "The player has " << countTotalItems(arr) << " items!\n";
    std::cout << "The player has " << arr[torch] << " torches\n";

    return 0;
}
