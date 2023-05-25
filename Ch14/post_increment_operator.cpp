#include <iostream>

class Digit
{
private:
    int m_digit;
public:
    Digit(int digit=0)
        : m_digit{digit}
    {
    }

    Digit& operator++();
    Digit& operator--();
    Digit operator++(int);  //post increment overloading
    Digit operator--(int);  //post decrement overloading     

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;

    return *this;
}

Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;

    return *this;
}

Digit Digit::operator++(int)
{
    Digit temp{*this};
    ++*this;
    return temp;
}

Digit Digit::operator--(int)
{
    Digit temp{*this};
    --*this;
    return temp;
}

std::ostream& operator<< (std::ostream& out, const Digit& d)
{
	out << d.m_digit;
	return out;
}

int main()
{
    Digit digit(5);

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    std::cout<<'\n';
    return 0;
}

// There are a few interesting things going on here. First, note that we’ve distinguished the prefix 
// from the postfix operators by providing an integer dummy parameter on the postfix version. 
// Second, because the dummy parameter is not used in the function implementation, we have not even given it a name. 
// This tells the compiler to treat this variable as a placeholder, which means it won’t warn us that we declared a 
// variable but never used it.

