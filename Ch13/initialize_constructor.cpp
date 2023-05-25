#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
    {
        assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
    Fraction frac{34,0}; // calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() <<'='<<frac.getValue()<< '\n';

    return 0;
}