#include <iostream>
#include <stdexcept>
#include <cassert>
#include "fraction.hpp"

int main()
{
    try
    {
        test_fraction();
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Test failed: " << e.what() << '\n';
    }
    return 0;
}
