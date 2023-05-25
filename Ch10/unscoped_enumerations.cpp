#include <iostream>

enum Color
{
    red,
    green,
    blue,
};

int main()
{
    Color shirt{ red };

    if (shirt == red) // if the shirt is blue
        std::cout << "Your shirt is red!"<<" shirt ="<<shirt;
    else
        std::cout << "Your shirt is not red!";
    std::cout <<'\n';

    return 0;
}