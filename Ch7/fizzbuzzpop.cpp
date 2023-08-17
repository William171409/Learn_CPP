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
        bool untriggered{1};
        if(i%3==0)
        {
            untriggered=0;
            std::cout<<"fizz";
        }
        if(i%5==0)
        {
            untriggered=0;
            std::cout<<"buzz";
        }
        if(i%7==0)
        {
            untriggered=0;
            std::cout<<"pop";
        }
        if(untriggered)
            std::cout<<i;
        std::cout<<'\n';

    }
}

int main()
{
    int endNum{getInt()};
    fizzbuzz(endNum);
    return 0;
}