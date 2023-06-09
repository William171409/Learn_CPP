#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    // Your code here

    if (bits.test(3))
        return (bits << 1).set(0);
    else
        return bits << 1;
}

int main()
{
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';

    std::bitset<4> bits3{0b1100};
    std::cout << rotl(bits2) << '\n';

    return 0;
}