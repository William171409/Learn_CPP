#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Integer Break

/*
Given an integer n, break it into the sum of k positive integers,
where k >= 2,
and maximize the product of those integers.
Return the maximum product you can get.
*/

int integerBreak(int n)
{

    if (n <= 2)
        return 1;

    vector<int> maxArr(n + 1, 0);

    /** For a number i: write i as a sum of integers, then take the product of those integers.
    maxArr[i] = maximum of all the possible products */

    maxArr[1] = 0;
    maxArr[2] = 1; // 2=1+1 so maxArr[2] = 1*1

    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            /** Try to write i as: i = j + S where S=i-j corresponds to either one number or a sum of two or more numbers

            Assuming that j+S corresponds to the optimal solution for maxArr[i], we have two cases:
            (1) i is the sum of two numbers, i.e. S=i-j is one number, and so maxArr[i]=j*(i-j)
            (2) i is the sum of at least three numbers, i.e. S=i-j is a sum of at least 2 numbers,
            and so the product of the numbers in this sum for S is maxArr[i-j]
            (=maximum product after breaking up i-j into a sum of at least two integers):
            maxArr[i] = j*maxArr[i-j]
            */
            maxArr[i] = max(maxArr[i], max(j * (i - j), j * maxArr[i - j]));
        }
    }
    return maxArr[n];
}

// 4 divisors

/*

Given an integer array nums, return the sum of divisors of the integers
in that array that have exactly four divisors. If there is no such integer in the array,
return 0.

*/

int sumFourDivisors(vector<int> &nums)
{
    int sum_divisors{0};
    for (auto num : nums)
    {
        int count_divisors{0};
        int partial_sum{0};
        for (auto i = 1; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                if (i != num / i)
                {
                    partial_sum += i + num / i;
                    count_divisors += 2;
                }
                else
                {
                    partial_sum += i;
                    count_divisors += 1;
                }
            }
        }
        if (count_divisors == 4)
            sum_divisors += partial_sum;
    }
    return sum_divisors;
}

// 3sum
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++)
    {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back)
        {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else
            {
                vector<int> triplet = {num[i], num[front], num[back]};
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number
                // forwards
                while (front < back && num[front] == triplet[1])
                    front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number
                // backwards
                while (front < back && num[back] == triplet[2])
                    back--;
            }
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i])
            i++;
    }

    return res;
}
