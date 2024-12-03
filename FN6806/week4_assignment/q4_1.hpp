#pragma once
#include <iostream>
#include <cmath>
const auto epsilon{1e-6};
class OptionWithComparison
{
    double strike;

public:
    OptionWithComparison(double s) : strike{s}
    {
        std::cout << "Strike price = " << strike << '$' << std::endl;
    }
    bool operator<(const OptionWithComparison &o) const
    {
        return strike < o.strike - epsilon;
    }

    friend std::ostream &operator<< (std::ostream & os, const OptionWithComparison &o)
    {
        // write the private member to stream
        os << o.strike;
        return os;
    }
};
class OptionWithoutComparison
{
    double strike;

public:
    OptionWithoutComparison(double s) : strike{s}
    {
        std::cout << "Strike price = " << strike << '$' << std::endl;
    }
    double getStrike() const
    {
        return strike;
    }
    friend std::ostream &operator<< (std::ostream & os, const OptionWithoutComparison &o)
    {
        // write the private member to stream
        os << o.strike;
        return os;
    }


};

// template <typename T>
// T mymax(T a, T b)
// {
//     return a < b ? b : a;
// }

// template <> OptionWithoutComparison mymax<OptionWithoutComparison>(OptionWithoutComparison a, OptionWithoutComparison b)
// {
//     return (a.getStrike() < (b.getStrike() - epsilon)) ?a : b;
// }

void q4_1(void);
