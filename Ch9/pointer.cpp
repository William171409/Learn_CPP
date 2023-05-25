#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
    int x{ 5 };
    std::cout << x <<' '<< typeid(x).name()<<'\n'; // print the value of variable x

    int& ref_x{x};
    std::cout << ref_x<<' '<< typeid(ref_x).name() << '\n'; // print the value of the object that ref_x referring to
    
    const int& ref=5;
    std::cout << ref<<' '<< typeid(ref).name() << '\n'; // print the value of the object that ref referring to(right value rvalue)

    int* ptr{ &x }; // ptr holds the address of x
    std::cout << *ptr<<' '<< typeid(ptr).name() << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    //The address of the variables above
    std::cout<<"The address of "<<x<<" is "<<&x<<std::endl;
    std::cout<<"The address of "<<ref_x<<" is "<<&ref_x<<std::endl;
    std::cout<<"The address of "<<ref<<" is "<<&ref<<std::endl;
    std::cout<<"The address of "<<ptr<<" is "<<&ptr<<std::endl;


    return 0;
}