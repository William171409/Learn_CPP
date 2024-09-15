#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.


int numSquares(int n)
{
    // cntPerfectSquares[i] = the least number of perfect square numbers
    // which sum to i. Note that cntPerfectSquares[0] is 0.
    vector<int> cntPerfectSquares(n + 1, INT_MAX);
    cntPerfectSquares[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        // For each i, it must be the sum of some number (i - j*j) and
        // a perfect square number (j*j).
        for (int j = 1; j * j <= i; j++)
        {
            cntPerfectSquares[i] =
                min(cntPerfectSquares[i], cntPerfectSquares[i - j * j] + 1);
        }
    }

    return cntPerfectSquares.back();
}

