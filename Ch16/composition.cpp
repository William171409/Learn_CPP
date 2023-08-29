#include <string>
#include <iostream>
#include "Creature.hpp"
#include "Point2D.hpp"

// To qualify as a composition, an object and a part must have the following relationship:

// The part (member) is part of the object (class)
// The part (member) can only belong to one object (class) at a time
// The part (member) has its existence managed by the object (class)
// The part (member) does not know about the existence of the object (class)

// Essentially, it models a 'has a' or 'part of' relationship

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{ name, { 4, 7 } };

    while (true)
    {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y{ 0 };
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    }

    return 0;
}