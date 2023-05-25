#include <iostream>

// return the sum of all the integers between 1 (inclusive) and sumto (inclusive)
// returns 0 for negative numbers
int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0; // base case (termination condition) when user passed in an unexpected argument (0 or negative)
    if (sumto == 1)
        return 1; // normal base case (termination condition)
    --sumto;
    return sumTo(sumto) + sumto+1; // recursive function call
}

int Fibonaccicount(int a)
{
    if (a == 1||a==0)
        return 1; // normal base case (termination condition)
    return Fibonaccicount(a-1)+Fibonaccicount(a-2)+1;
}
void sumFibonnacicount(int& sumCount,int a)
{
    if(a>=0)
    {
        sumCount+=Fibonaccicount(a);
        sumFibonnacicount(sumCount,a-1);
    }
}
int main()
{
    int total_count{};
    std::cout << "Sum from 1 to 5: " << sumTo(10) << '\n';

    std::cout << "Fibonacci get count f(12) requires total number of operations of : " << Fibonaccicount(12) << '\n';
    sumFibonnacicount(total_count,12);
    
    std::cout << "\nFibonacci get count from 12 to 1 requires total number of operations of : " << total_count << '\n';
    return 0;
}