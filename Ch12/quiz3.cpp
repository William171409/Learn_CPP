// Binary Search

#include <iostream>
#include <iterator>
#include <cassert>
// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int iterative_binarySearch(const int *array, int target, int min, int max)
{
    assert(array); // make sure array exists avoid dangling dereference

    while (true)
    {
        if (max < min)
            return -1;
        if (target == array[(min + max) / 2])
            return (min + max) / 2;
        else if (target < array[(min + max) / 2])
            max = (min + max) / 2 - 1;
        else
            min = (min + max) / 2 + 1;
    }
}

int recursive_binarySearch(const int *array, int target, int min, int max)
{
    assert(array); // make sure array exists avoid dangling dereference

    if (max < min)
        return -1;
    else if (target == array[(min + max) / 2])
        return (min + max) / 2;
    else
        return (target < array[(min + max) / 2]) ? recursive_binarySearch(array, target, min, (min + max) / 2 - 1) : recursive_binarySearch(array, target, (min + max) / 2 + 1, max);
}

int main()
{
    constexpr int array[]{3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48};

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{10};
    // Here are the test values
    constexpr int testValues[numTestValues]{0, 3, 12, 13, 22, 26, 43, 44, 49, 32};
    // And here are the expected results for each value
    int expectedValues[numTestValues]{-1, 0, 3, -1, -1, 8, -1, 13, -1, 9};

    // Loop through all of the test values
    for (int count{0}; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{recursive_binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1)};
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}