#include <iostream>
#include <numeric> // for std::gcd

//Pay attention to the invalid input cases!!!
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, int value);
    friend Fraction operator*(int value, const Fraction &f1);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f);
    friend std::istream &operator>>(std::istream &, Fraction &);

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
    int getNum()const{return m_numerator;}
    int getDeonom()const{return m_denominator;}

};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, int value)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction &f1)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &f)
{
    while(true)
    {
        in >> f.m_numerator;
        if(in.fail())
        {
            in.clear();
            ignoreLine();
            std::cerr<<"Oops, that input numerator is invalid. Please enter an integer!\n";
        }
        else
        {
            ignoreLine();
            break;
        }

    }
    while(true)
    {
        in >> f.m_denominator;
        if(in.fail())
        {
            in.clear();
            ignoreLine();
            std::cerr<<"Oops, that input denominator is invalid. Please enter an integer!\n";
        }
        else
        {
            ignoreLine();
            break;
        }

    }

    f.reduce();
    return in;
}

int main()
{
    Fraction f1;
    std::cout << "Enter fraction 1(numerator fisrt): \n";
    std::cin >> f1;
    std::cout<<"f1 = "<<f1<<'\n';

    Fraction f2;
    std::cout << "Enter fraction 2(numerator fisrt): \n";
    std::cin >> f2;
    std::cout<<"f2 = "<<f2<<'\n';
    if(f1.getDeonom()==0||f2.getDeonom()==0)
        std::cout << f1 << " * " << f2 << " is invalid! Divisor should be non-zero!" << '\n'; // note: The result of f1 * f2 is an r-value
    else
        std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
