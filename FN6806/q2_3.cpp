#include <iostream>
#include <stdexcept>
#include <cassert>
#include "fraction.hpp"

void test_fraction()
{

    Fraction f1;
    if (f1.get_nom() != 0 || f1.get_denom() != 1)
    {
        throw std::logic_error("Default constructor failed.");
    }

    Fraction f2(5);
    if (f2.get_nom() != 5 || f2.get_denom() != 1)
    {
        throw std::logic_error("Single-parameter constructor failed.");
    }

    Fraction f3(6, 8);
    if (f3.get_nom() != 3 || f3.get_denom() != 4)
    {
        throw std::logic_error("Two-parameter constructor or reduction failed.");
    }

    try
    {
        Fraction invalidFraction(1, 0);
        throw std::logic_error("Constructor did not throw for zero denominator.");
    }
    catch (const std::logic_error &e)
    {
    }

    if (f3.get_nom() != 3 || f3.get_denom() != 4)
    {
        throw std::logic_error("Accessors get_nom or get_denom failed.");
    }

    Fraction f4 = f3.add(Fraction(1, 4)); // 3/4 + 1/4 = 1/1
    if (f4.get_nom() != 1 || f4.get_denom() != 1)
    {
        throw std::logic_error("Addition failed.");
    }

    Fraction f5 = f3.mult(Fraction(2, 3)); // 3/4 * 2/3 = 1/2
    if (f5.get_nom() != 1 || f5.get_denom() != 2)
    {
        throw std::logic_error("Multiplication failed.");
    }

    Fraction f6(2, 3);
    Fraction f7 = f6.reciprocal(); // 3/2
    if (f7.get_nom() != 3 || f7.get_denom() != 2)
    {
        throw std::logic_error("Reciprocal failed.");
    }

    try
    {
        Fraction zeroNumerator(0, 5);
        zeroNumerator.reciprocal();
        throw std::logic_error("Reciprocal did not throw for zero numerator.");
    }
    catch (const std::logic_error &e)
    {
    }

    std::cout << "All tests passed successfully.\n";
}
