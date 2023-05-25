#include <iostream>

class Rectangle
{
private:
    double m_length{ 1.0 };
    double m_width{ 1.0 };

public:

    Rectangle(double length, double width)
        : m_length{ length },
          m_width{ width }
    {
        // m_length and m_width are initialized by the constructor (the default values aren't used)
    }

    Rectangle(double length)
        : m_length{ length }
    {
        // m_length is initialized by the constructor.
        // m_width's default value (1.0) is used.
    }

    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }

};

int main()
{
    Rectangle x{ 2.0, 3.0 };
    x.print();

    Rectangle y{ 4.0 };
    y.print();

    return 0;
}