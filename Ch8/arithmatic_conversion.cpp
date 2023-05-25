#include <iostream>

int main()
{

    int a{8};
    int b{1 << 30};
    // long long c = a * b;

    //Notice that c = 0 as no  arithmatic conversion is conducted since both a
    // and b are ints and a*b causes an overflow and output int 0 which is then 
    // promoted to long long 0

    //To get long long c correcly, using explicit type conversion static_cast<>
    long long c = static_cast<long long>(a) * b;
    
    std::cout<<"The result is "<<c<<std::endl;

    return 0;
}