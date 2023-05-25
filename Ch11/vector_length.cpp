#include <iostream>
#include <vector>

// To pass std::array or std::vector, we must specify the <type> template
void printLength(const std::vector<auto>& v)
{
    std::cout << "The length is: " << v.size() << '\n';
}

int main()
{
    std::vector v{ 9, 7, 5, 3, 1,23 };
    printLength(v);

    std::vector<int> empty {};
    printLength(empty);

    return 0;
}