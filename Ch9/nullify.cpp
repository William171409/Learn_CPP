#include <iostream>
#include <cassert>


// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]]const int* ptr2)
{
    // *ptr2=9;
    ptr2 = nullptr; // Make the function parameter a null pointer
    // assert(ptr2);

}

void nullify([[maybe_unused]]int*& ptr2)
{
    // *ptr2=9;
    ptr2 = nullptr; // Make the function parameter a null pointer
    // assert(ptr2);

}


int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    if(ptr!=nullptr)
        std::cout << "*ptr is "<<*ptr << std::endl;

    nullify(ptr);
    std::cout << "\nAfter nullify()\n"<< std::endl;

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    if(ptr!=nullptr)
        std::cout << "*ptr is "<<*ptr << std::endl;
    return 0;
}