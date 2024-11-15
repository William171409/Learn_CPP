#pragma once
#include <iostream>
#include <stdexcept>

class Fraction
{
    int _nom;
    int _denom;

public:
    Fraction() : _nom{0}, _denom{1} {}
    Fraction(int x, int y = 1) : _nom{x}, _denom{y}
    {
        if (y == 0)
        {
            throw std::logic_error("Denominator cannot be zero.");
        }
        reduce();
    }

    // Define Ctor to initializes the fraction
    // `Fraction(x, y)` ^> fraction x/y.
    // `Fraction(x)` ^> fraction x/1.
    // `Fraction()` ^> fraction 0/1.
    // `Fraction(x, 0)` ^> throw logic_error.
    // What else?
    // Do you need to define other special functions?

    int get_nom() const
    {
        return _nom;
    };
    // Returns numerator

    int get_denom() const
    {
        return _denom;
    }
    // Returns denominator

    void print() const
    {
        std::cout << _nom << '/' << _denom << '\n';
    }
    // prints fraction to screen, format a/b

    void reduce()
    {
        int gcd_num{gcd(_nom, _denom)};
        _nom /= gcd_num;
        _denom /= gcd_num;
    }
    // divide num and denom by their gcd

    Fraction reciprocal() const
    {
        return Fraction{_denom, _nom};
    }
    // F.reciprocal returns reciprocal of F

    Fraction add(const Fraction &G) const
    {
        return Fraction{_nom * G._denom + G._nom * _denom, _denom * G._denom};
    }
    // F.add(G) returns F+G

    Fraction mult(const Fraction &G) const
    {
        return Fraction{_nom * G._nom, _denom * G._denom};
    }
    // F.mult(G) returns FG
private:
    int gcd(int u, int v)
    {
        if (u < 0)
            u = -u;
        if (v < 0)
            v = -v;
        int r;
        while (v != 0)
        {
            r = u % v;
            u = v;
            v = r;
        }
        return u;
    }
};

void test_fraction(void);