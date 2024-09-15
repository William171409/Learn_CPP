#include <iostream>
#include <cmath>
// Write down a C++ function with function head
// int NumRep(int n)
// which returns the number of representations of n as a sum of 3 positive
// squares, i.e., the number of triples (a, b, c) with
// 1 ≤ a ≤ b ≤ c with a2 + b2 + c2 = n.
// Examples: The only representation of 3 as a sum of 3 squares is 3 = 1+1+1,
// so the function should return 1 if n is 3. If n is 27, the function should return
// 2 since 27 has exactly 2 such representations: 27 = 25 + 1 + 1 = 9 + 9 + 9

int NumRep(int n);

int main()
{   
    int n{27};
    std::cout<<"n = "<<n<<"\nnumber of representaions = "<<NumRep(n)<<std::endl;
    while(n<1000)
    {
        if(NumRep(n)>=6)
        {
            std::cout<<"Smallest qualified integer is "<<n<<std::endl;
            break;
        }
        n++;
    }
    return 0;
}


int NumRep(int n)
{
    if (n<3)
        return 0;
    int num_rep{0};
    for (auto a = 1; a * a <= n; ++a) {
        // Loop for b, starting from a to ensure a <= b
        for (int b = a; b * b + a * a < n; ++b) {
            // Calculate remaining sum for c
            int remaining = n - (a * a + b * b);
            
            // Check if remaining is a perfect square
            int c = static_cast<int>(sqrt(remaining));
            
            // If c^2 == remaining and b <= c, it's a valid triple
            if (c * c == remaining && b <= c) {
                ++num_rep;
            }
        }
    }

    return num_rep;
}