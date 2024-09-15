#include <iostream>
#include <cmath>
// Find all prime divisors of an integer n (include repeated one)

void PrintPrimeDiv(int n);
int main()
{
    int n{1000001};
    std::cout << "Prime divisors of " << n << ": \n";
    PrintPrimeDiv(n);
    std::cout<<std::endl;
}

void PrintPrimeDiv(int n)
{
    if (n < 2)
        return;
    while (n % 2 == 0)
    {
        std::cout << "2 ";
        n /= 2;
    }

    for (auto i = 3; i <= static_cast<int>(std::sqrt(n)); i += 2)
    {
        while (n % i == 0)
        {
            std::cout << i << ' ';
            n /= i;
        }
    }
    if (n>2)
    {
        std::cout<<n;
    }
}