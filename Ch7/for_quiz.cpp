#include <iostream>

void sumTo(int a)
{
    int sum = 1;
    int b =  a;
    if (a > 1)
    {
        while (a > 1)
        {
            sum += a;
            a--;
        }
    }
    else if (a < 1)
    {
        /* code */
        while (a < 1)
        {
            sum += a;
            a++;
        }
    }
    std::cout << "Sum of 1 to " << b << " = " << sum<<std::endl;
}
int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    sumTo(x);

    return 0;
}