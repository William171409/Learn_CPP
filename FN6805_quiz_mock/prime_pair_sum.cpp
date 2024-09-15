#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void getprime(vector<int> &prime_vec, int n)
{
    if (n < 2)
        return;
    vector<bool> aux_vec(n, true);

    for (auto i = 2; i <= sqrt(n - 1); i++)
    {
        if (aux_vec[i])
        {
            for (auto j = i * i; j <= n - 1; j = j + i)
            {
                aux_vec[j] = false;
            }
        }
    }

    for (auto i = 2; i <= n - 1; i++)
    {
        if (aux_vec[i])
            prime_vec.push_back(i);
    }
}

vector<vector<int>> findPrimePairs(int n)
{
    vector<int> prime_arr{};
    vector<vector<int>> result{};
    getprime(prime_arr, n);

    if (prime_arr.size() < 1)
    {
        return result;
    }
    else
    {
        for (auto x = 2; x <= n / 2; x++)
        {
            if (find(prime_arr.begin(), prime_arr.end(), x) != prime_arr.end() && find(prime_arr.begin(), prime_arr.end(), n - x) != prime_arr.end())
                result.push_back({x, n - x});
        }
        return result;
    }
}

// int main()
// {

//     for(auto& vec_element:findPrimePairs(10000))
//     {
//         for(auto element:vec_element)
//         {
//             std::cout<<element<<' ';
//         }
//         std::cout<<'\n';
//     }
//     return 0;
// }