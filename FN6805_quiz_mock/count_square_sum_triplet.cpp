// A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 + b^2 = c^2.

// Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.


#include <iostream>
    int countTriples(int n) {
     int count{0};   
     for(auto a=1;a<n;a++){
        for(auto b=1;b<n;b++){
            int sqrt_sum_square{static_cast<int>(sqrt(a*a+b*b))};
            if ((sqrt_sum_square*sqrt_sum_square==a*a+b*b)&&sqrt_sum_square<=n)
            {
                count++;
            }
            
        }
     }
     return count;   
    }
