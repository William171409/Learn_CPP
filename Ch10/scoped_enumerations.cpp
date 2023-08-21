// Question #1

// Define an enum class named Animal that contains the following
// animals: pig, chicken, goat, cat, dog, duck.
// Write a function named getAnimalName() that takes an Animal parameter
// and uses a switch statement to return the name for that animal
// as a std::string_view (or std::string if you’re using C++14).
// Write another function named printNumberOfLegs() that uses a switch
// statement to print the number of legs each animal walks on.
// Make sure both functions have a default case that prints an error message.
// Call printNumberOfLegs() from main() with a cat and a chicken.
// Your output should look like this:

// A cat has 4 legs.
// A chicken has 2 legs.

#include <iostream>
#include <string_view>
#include <string>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

/*Attention: If this function is return-by-reference and return "cat" and etc. directly,
it will cause the dangling references which means, the reference object returned by
the function is a reference object while the referent is already destroyed!*/
std::string_view getAnimalname(Animal animal)
{
    using enum Animal;
    switch (animal)
    {
    case cat:
        return "cat";
    case chicken:
        return "chicken";
    case dog:
        return "dog";
    case duck:
        return "duck";
    case goat:
        return "goat";
    case pig:
        return "pig";
    default:
        return "unkown";
    }
}
int printNumberOfLegs(Animal animal)
{
    using enum Animal;
    switch (animal)
    {
    case cat:
        return 4;
    case chicken:
        return 2;
    case dog:
        return 4;
    case duck:
        return 4;
    case goat:
        return 4;
    case pig:
        return 4;
    default:
        return -1;
    }
}
int main()
{
    using enum Animal;
    std::cout << "A " << getAnimalname(cat) << " has " << printNumberOfLegs(cat) << " legs" << std::endl;
    std::cout << "A " << getAnimalname(chicken) << " has " << printNumberOfLegs(chicken) << " legs" << std::endl;

    return 0;
}