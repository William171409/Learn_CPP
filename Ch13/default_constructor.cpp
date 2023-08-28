#include <iostream>

class Fraction
{
private:
    int m_numerator{} ;
    int m_denominator{} ;

public:
    Fraction() // default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
    Fraction frac{}; // calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() <<'='<<frac.getValue()<< '\n';

    return 0;
}