#include <iostream>

int main()
{
    unsigned int u { 123058520u }; // 5u means the number 5 as an unsigned int
    int16_t s { static_cast<int16_t>(u) }; // return value of variable u as an int

    std::cout << u<<std::endl;
    std::cout << s<<std::endl;
    std::cout << 070<<std::endl;

    return 0;
}