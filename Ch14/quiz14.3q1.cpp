#include "Blocks.hpp"
#include <iostream>

//fucntion definition for the forward declaration of function get blocks...
int Blocks::getBlocks()const
{
    return m_block;
}

Blocks Blocks::operator+(int value)
{
    std::cout<<"operator value called!\n";
    return getBlocks() + value;
}

Blocks operator+(const Blocks& b1, const Blocks& b2)
{
    std::cout<<"operator two blocks called!\n";
    return b1.getBlocks() + b2.getBlocks();
}

int main()
{
    Blocks b1{2};
    Blocks b2{3};

    // Using member function '+' to add a Blocks object and an integer
    Blocks result1 = b1 + 4;
    std::cout << "Result of member function +: " << result1.getBlocks() << '\n';

    // Using regular function '+' to add two Blocks objects
    Blocks result2 = b1 + b2;
    std::cout << "Result of regular function +: " << result2.getBlocks() << '\n';
    return 0;
}