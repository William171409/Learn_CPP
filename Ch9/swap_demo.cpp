#include <algorithm>
#include <iostream>

template <typename T>
void interchange(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int a{12};
    int b{43};
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;

    // Built in library <algorithm>
    //  std::swap(a, b);

    interchange(&a, &b);
    //  my own swap (a, b);
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;

    return 0;
}