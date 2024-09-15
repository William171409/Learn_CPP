#include <iostream>
#include <cmath>

int NumRep(int n);
void PrintPrimeDiv(int n)
{
    if (n<=1)
        return;

    while(n%2==0)
    {
        std::cout<<"2 ";
        n/=2; 
    }

    for(auto i = 3;i<=((int)std::sqrt(n));i=i+2)
    {
        while(n%i==0)
        {
           std::cout<<i<<' ';
           n/=i; 
        }
    }

    if(n!=1)
    {
        std::cout<<n;
    }
    std::cout<<'\n';
}

int NumberPayments(int sum, int c1, int c2, int c3)
{
    
}

int main()
{
    // std::cout<<NumRep(3)<<std::endl;
    // for(auto i = 27+1;i<1000;i++)
    // {
    //     int num{NumRep(i)};
    //     if(NumRep(i)>=6)
    //     {
    //         std::cout<<i<<std::endl;
    //         break;
    //     }
            
    // }
    PrintPrimeDiv(1000001);
    return 0;
}

int NumRep(int n)
{
    int num_rep{0};
    if(n<=2)
        return 0;
    else
    {
        for(auto a=1;a*a<n;a++)
        {
            for(auto b = a;a*a+b*b<n;b++)
            {
                int remain{n - a*a - b*b};
                if (static_cast<int>(std::sqrt(n-a*a-b*b))>=b&&(static_cast<int>(std::sqrt(n-a*a-b*b))*static_cast<int>(std::sqrt(n-a*a-b*b)))==(n-a*a-b*b))
                {
                    num_rep++;
                }
            }
        }
        return num_rep;
    }
}



