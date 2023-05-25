#ifndef BLOCKS_HPP
#define BLOCKS_HPP

class Blocks
{
private:
    int m_block{};
public:
    //constructor
    Blocks(int value) : m_block{value}
    {
        //correct, don't forget the constructors function body.
    }

    //forward declaration for the getBlock function...
    int getBlocks()const;  //correct, the forward declaration of the function prototype doesn't require the definition of the function as it is defined in the .cpp
    //a friend function to add blocks together?
    //a member function to add the blocks together...
    //Below, the class itself has ownership of the overloaded + operator... The left hand operand of the + operator is the class itself.
    Blocks operator+(int value); //has a hidden this* to operate on this object, the left hand operand is the hidden this*
};

Blocks operator+(const Blocks& b1, const Blocks& b2);

#endif // BLOCKS_H_INCLUDED