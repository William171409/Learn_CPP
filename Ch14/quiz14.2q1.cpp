#include <iostream>
#include <numeric>

class Fraction
{
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int a = 0, int b = 1) : m_numerator{a}, m_denominator{b}
    {
        reduce();
    }
    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << std::endl;
    }
    void reduce()
    {
        if(m_denominator!=0)
        {   
            if(m_numerator!=0)
            {    int tempGcd{std::gcd(m_numerator,m_denominator)};
                m_numerator/=tempGcd;
                m_denominator/=tempGcd;
            }
        }
    }
    friend Fraction operator*(const Fraction &f1, const Fraction &f2)
    {
        return {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
    }

    friend Fraction operator*(const Fraction &f, const int a)
    {
        return {f.m_numerator * a, f.m_denominator};
    }
    friend Fraction operator*(const int a, const Fraction &f)
    {
        return f * a;
    }
};

int main()
{
    Fraction f1{2, 0};
    f1.print();

    Fraction f2{1, 7};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}

