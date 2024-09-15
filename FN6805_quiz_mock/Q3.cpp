#include <iostream>

// find number of unique payments that could be paid by 3 types of coins

int NumberPayments(int sum, int c1, int c2, int c3);

int single_value_pay(int val, int sum)
{
    if (sum <= 0)
        return 0;
    return (sum % val == 0) ? 1 : 0;
}

int double_value_pay(int val1, int val2, int sum)
{
    int n{sum};
    if ((val1 + val2) < sum)
    {
        // while (n - (val1 + val2) >= 0)
        // {
        //     n -= (val1 + val2);
        // }

        // if (n == 0 || n == val1 || n == val2)
        //     return 1 else return 0;
        return double_value_pay(val1, val2, n - (val1 + val2)) + single_value_pay(val1, n - (val1 + val2)) + single_value_pay(val2, n - (val1 + val2));
    }
    else if ((val1 + val2) == sum)
    {
        return 1;
    }
    else
        return 0;
}

int triple_value_pay(int val1, int val2, int val3, int sum)
{
    int n{sum};
    if ((val1 + val2 + val3) < sum)
    {
        int remain{sum - val1 - val2 - val3};
        return triple_value_pay(val1, val2, val3, remain) + single_value_pay(val1, remain) + single_value_pay(val2, remain) + single_value_pay(val3, remain) + double_value_pay(val1, val2, remain) + double_value_pay(val1, val3, remain) + double_value_pay(val3, val2, remain);
    }
    else if ((val1 + val2 + val3) == sum)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    std::cout << NumberPayments(10, 5, 2, 3) << std::endl;
    return 0;
}

int NumberPayments(int sum, int c1, int c2, int c3)
{
    return single_value_pay(c1, sum) + single_value_pay(c2, sum) + single_value_pay(c3, sum) + double_value_pay(c1, c2, sum) + double_value_pay(c1, c3, sum) + double_value_pay(c2, c3, sum) + triple_value_pay(c1, c2, c3, sum);
}