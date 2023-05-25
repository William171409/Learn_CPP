#include <iostream>

int main()
{
    bool b{-45};

    //Usage of boolalpha is to output boolean data type in 'true/false' form
    std::cout << std::boolalpha;
    
    std::cout << b<<std::endl;

    return 0;
}