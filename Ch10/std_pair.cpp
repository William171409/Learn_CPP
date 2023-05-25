#include <utility> // for std::pair
#include <iostream>
int main()
{
    std::pair<int, int> p1{ 1, 2 }; // explicitly specify class template std::pair<int, int> (C++11 onward)
    std::pair p2{ 1, 2 };           // CTAD used to deduce std::pair<int, int> from the initializers (C++17)
    std::cout<<p2.first<<'\t'<<p2.second<<std::endl;
    return 0;
}