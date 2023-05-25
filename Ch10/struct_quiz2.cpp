#include <iostream>
#include <limits>

struct Fraction
{
    int numerator{};
    int denominator{};
};

// Exception handler
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// get an integer
int getInt()
{
    int a{};
    while (true)
    {
        std::cin >> a;
        // Check for failed extraction
        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();     // and remove the bad input
            std::cerr << "Oops, that input is invalid.  Please try again: ";
        }
        else
        {
            ignoreLine(); // remove any extraneous input
            return a;
        }
    }
}
Fraction getFraction()
{
    Fraction fra{};
    std::cout << "Enter a value for the numerator: ";
    fra.numerator = getInt();
    
    do
    {
        std::cout << "Enter a value for the denominator(non-zero): ";
        fra.denominator = getInt();
    } while (fra.denominator == 0);
    return fra;
}
Fraction fraction_multiplication(const Fraction &f1, const Fraction &f2)
{
    std::cout << "fraction 1 = " << f1.numerator << '/' << f1.denominator << std::endl;
    std::cout << "fraction 2 = " << f2.numerator << '/' << f2.denominator << std::endl;
    return Fraction{(f1.numerator * f2.numerator), (f1.denominator * f2.denominator)};
}
void fraction_print(const Fraction &f)
{
    std::cout << "The multiplication of the two fractions = " << f.numerator << '/' << f.denominator << '\n';
}
int main()
{
    std::cout<<"Fraction 1\n\n";
    Fraction fra1 = getFraction();
    std::cout<<"Fraction 2\n\n";
    Fraction fra2 = getFraction();
    fraction_print(fraction_multiplication(fra1, fra2));
    return 0;
}