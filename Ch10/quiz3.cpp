#include "triad.hpp"
#include <iostream>
#include <string_view>
template <typename T, typename U, typename V>
Triad(T, U, V) -> Triad<T, U, V>;

template <typename T, typename U, typename V>
void print(const Triad<T, U, V> &tri)
{
    std::cout << '[' << tri.t1 << ", " << tri.t2 << ", " << tri.t3 << ']' << std::endl;
    std::cout << typeid(tri.t1).name() << " " << typeid(tri.t2).name() << " " << typeid(tri.t3).name() << '\n';
}

int main()
{

    Triad tri{6.0F, 56.02, 465.0F};
    print(tri);

    return 0;
}
/*Notice that, if we dont explicitly specify the type of the class template, the program will
    not be compiled
    note: uses CTAD to deduce template arguments
    No matter whether the class template has default type, always include  deduction guide to
    make sure the initialization can be done by STRUCT_NAME str{}; NO <DATA_TYPE>which specifies
    the type
*/
