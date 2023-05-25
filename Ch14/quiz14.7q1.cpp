#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
    {
        // We put reduce() in the constructor to ensure any new fractions we make get reduced!
        // Any fractions that are overwritten will need to be re-reduced
        reduce();
    }

    void reduce()
    {
        int gcd{std::gcd(m_numerator, m_denominator)};
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }
    bool validate() const
    {
        return m_denominator == 0;
    }
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
    friend bool operator==(const Fraction &f1, const Fraction &f2) { return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator); }
    friend bool operator!=(const Fraction &f1, const Fraction &f2) { return !(f1 == f2); }
    friend bool operator>(const Fraction &f1, const Fraction &f2)
    {
        
        return (static_cast<double>(f1.m_numerator) / f1.m_denominator - static_cast<double>(f2.m_numerator) / f2.m_denominator) > 0;
    }
    friend bool operator<(const Fraction &f1, const Fraction &f2) { return f2 > f1; };
    friend bool operator<=(const Fraction &f1, const Fraction &f2) { return !(f2 < f1); };
    friend bool operator>=(const Fraction &f1, const Fraction &f2) { return !(f2 > f1); };
};

std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int main()
{
    Fraction f1{1, 2};
    Fraction f2{3, 2};
    if (f1.validate() || f2.validate())
        std::cout << "It's trivial to compare " << f1 << " and " << f2 << " since denominator should not be 0!\n";
    else
    {
        std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
        std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
        std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
        std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
        std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
        std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
    }
    return 0;
}