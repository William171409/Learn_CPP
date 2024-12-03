#include "q4_2.hpp"
#include <iostream>
#include <string>
// class template  & class template member function definition
void q4_2()
{
    Pair<double, std::string> P(2.71828, "test");
    std::cout << P.left() << "\n";
    std::cout << P.right() << "\n";
    std::vector<int> v;
    std::list<double> L;
    for (int i = 0; i < 10; ++i) {
    v.push_back(i);
    L.push_back(i * 3.1415);
    }
    Pair<std::vector<int>, std::list<double>> P2(v, L);
    std::cout << P2.left().size() << "\n";
    std::cout << P2.right().size() << "\n";

    Pair<int, int> pp(2, 3);
    auto p2 = pp;
    std::cout<< std::boolalpha<<(p2 == pp) << "\n";
    p2.left(3);
    std::cout << (p2 == pp) << "\n";
}