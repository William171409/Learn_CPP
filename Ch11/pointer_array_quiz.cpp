#include <iostream>
#include <iterator>

// ...

int *findValue(int *start, int *end, int magic)
{
    while (start < end)
    {
        if (*start == magic)
            return start;
        start++;
    }
    return end;
}

int main()
{
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};

    // Search for the first element with value 20.
    int *found{findValue(std::begin(arr), std::end(arr), 40)};

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << found << '\n';
        std::cout << *found << '\n';
    }

    return 0;
}