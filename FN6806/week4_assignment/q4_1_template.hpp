#pragma once 
#include "q4_1.hpp"
template <typename T>
T mymax(T a, T b)
{
    return a < b ? b : a;
}

template <> OptionWithoutComparison mymax<OptionWithoutComparison>(OptionWithoutComparison a, OptionWithoutComparison b)
{
    return (a.getStrike() < (b.getStrike() - epsilon)) ?a : b;
}
