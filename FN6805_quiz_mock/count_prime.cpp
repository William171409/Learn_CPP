int countPrimes(int n)
{
    if (n <= 2)
        return 0;
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
    return accumulate(aux_vec.begin(), aux_vec.end(), 0) - 2;
}


// Question 2: Prime Divisors of a Number
// Theme: Prime factorization and divisors.

// Reverse Integer
// Description: Reverse digits of an integer. (Requires understanding integer properties, though not directly related to prime factors.)
int reverse(int x)
{
    int result = 0;

    while (x != 0)
    {
        int digit = x % 10; // Get the last digit
        x /= 10;            // Remove the last digit from x

        // Check for overflow before actually updating the result
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit > 7))
        {
            return 0; // Overflow for positive numbers
        }
        if (result < INT_MIN / 10 ||
            (result == INT_MIN / 10 && digit < -8))
        {
            return 0; // Overflow for negative numbers
        }

        // Update the result by shifting current digits and adding the new
        // one
        result = result * 10 + digit;
    }

    return result;
}


// Distinct Prime Factors of a Product
// Description: Find distinct prime factors of the product of two numbers. (Similar in concept to prime factorization.)
void primeFactors(long long int n, vector<int> &factor)
{
    int c = 2;
    while (n > 1)
    {
        if (n % c == 0)
        {
            factor.push_back(c);
            n /= c;
        }
        else
            c++;
    }
}

int distinctPrimeFactors(vector<int> &nums)
{
    long long int res = 1;
    int count = 0;
    vector<int> factor;
    for (int i = 0; i < nums.size(); i++)
    {
        primeFactors(nums[i], factor);
    }

    map<int, int> mapping;
    for (auto i : factor)
        mapping[i]++;
    return mapping.size();
}
