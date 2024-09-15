// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

bool isUgly(int n)
{
    for (int i = 2; i < 6 && n; i++)
        while (n % i == 0)
            n /= i;
    return n == 1;
}

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

int nthUglyNumber(int n)
{
    if (n <= 0)
        return false; // get rid of corner cases
    if (n == 1)
        return true;            // base case
    int t2 = 0, t3 = 0, t5 = 0; // pointers for 2, 3, 5
    vector<int> k(n);
    k[0] = 1;
    for (int i = 1; i < n; i++)
    {
        k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
        if (k[i] == k[t2] * 2)
            t2++;
        if (k[i] == k[t3] * 3)
            t3++;
        if (k[i] == k[t5] * 5)
            t5++;
    }
    return k[n - 1];
}
