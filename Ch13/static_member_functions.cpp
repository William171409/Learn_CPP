#include <iostream>

class Something
{
private:
    static int s_value;
public:
    static int getValue() { return s_value; } // static member function
};

int Something::s_value{ 100 }; // initializer

int main()
{
    std::cout << Something::getValue() << '\n';
}

/*Because static member functions are not attached to a particular object, 
they can be called directly by using the class name and the scope resolution 
operator. Like static member variables, they can also be called through 
objects of the class type, though this is not recommended.
*/
