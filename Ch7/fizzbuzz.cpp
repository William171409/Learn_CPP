#include <iostream>

int getInt()
{
    std::cout << "Enter an integer:";
    int num{};
    std::cin >> num;
    return num;
}

void fizzbuzz(int endnum)
{
    for (int i{1}; i <= endnum; i++)
    {
        if ((i % 3 == 0) && (i % 5 != 0))
            std::cout << "fizz";
        else if ((i % 3 != 0) && (i % 5 == 0))
            std::cout << "buzz";
        else if ((i % 3 == 0) && (i % 5 == 0))
            std::cout << "fizzbuzz";
        else
            std::cout << i;
        std::cout << std::endl;
    }
}

int main()
{
    int endNum{getInt()};
    fizzbuzz(endNum);
    return 0;
}