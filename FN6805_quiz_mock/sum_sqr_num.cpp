#include <iostream>
#include <set>
// Given a non-negative integer c, decide whether there're two integers a and b such
//  that a^2 + b^2 = c.

// hillbilly solution
// bool judgeSquareSum(int c) {

//     int sqrt_c = static_cast<int>(sqrt(c));

//     for(long long i = 0; i<=sqrt_c;i++)
//     {
//         for(long long j=i;j<=sqrt_c;j++)
//         {
//             if (i*i+j*j-c ==0)
//                 return true;
//         }
//     }
//     return false;
// }


bool judgeSquareSum(int c)
{
    for (int divisor = 2; divisor * divisor <= c; divisor++)
    {
        if (c % divisor == 0)
        {
            int exponentCount = 0;
            while (c % divisor == 0)
            {
                exponentCount++;
                c /= divisor;
            }
            if (divisor % 4 == 3 && exponentCount % 2 != 0)
            {
                return false;
            }
        }
    }
    return c % 4 != 3;
}

// int main()
// {
//     std::set<int> set1{};
//     set1.insert(1);
//     set1.insert(1);
//     for (auto i : set1)
//     {
//         std::cout << i << '\n';
//     }
// }
void test_permutations(int num_permutations) {
    // 2D vector to count occurrences, 100 rows (for each index) and 100 columns (for each number)
    std::vector<std::vector<int>> occurrences(100, std::vector<int>(100, 0));

    // Run permutation multiple times
    for (int i = 0; i < num_permutations; ++i) {
        std::array<int, 100> perm = permutation();
        // Increment the count for each number at each index
        for (std::size_t index = 0; index < perm.size(); ++index) {
            occurrences[index][perm[index]]++;
        }
    }

    // Print the results
    for (std::size_t index = 0; index < occurrences.size(); ++index) {
        std::cout << "Index " << index << ": ";
        for (std::size_t num = 0; num < occurrences[index].size(); ++num) {
            std::cout << occurrences[index][num] << " ";
        }
        std::cout << std::endl;
    }
}
