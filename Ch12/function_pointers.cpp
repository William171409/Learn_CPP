#include <iostream>
#include <array>
#include <vector>
#include <iterator>


//FUnciton name itself is actually a pointer as well! 
double foo() // code starts at memory address 0x002717f0
{
    return 12568.14;
}

int goo(int a)
{
    return  a;
}
int main()
{
    std::cout << reinterpret_cast<void*>(foo) << '\n'; // we meant to call foo(), but instead we're printing foo itself!
    std::cout << foo() << '\n'; // we meant to call foo(), but instead we're printing foo itself!
    
    int (*fcnPtr)(int){ &goo }; // Initialize fcnPtr with function foo
    std::cout<<fcnPtr(5)<<'\n'; // call function foo(5) through fcnPtr.(implicit dereference)
    std::cout<<(*fcnPtr)(5)<<'\n'; // call function foo(5) through fcnPtr.
    std::cout<<goo(5)<<'\n'; // call function foo(5) through fcnPtr.

    return 0;
}
