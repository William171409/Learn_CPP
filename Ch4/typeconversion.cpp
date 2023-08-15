#include <iostream>

void printNum(int num)
{
    std::cout << num << '\n';
}

int main()
{
    double a{3.3};
    
    // The printed number will be 3 as the num is implicitly converted!
    printNum(a);
    printNum(static_cast<int>(78.612));

    return 0;
}