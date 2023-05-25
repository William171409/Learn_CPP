#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
    // Our non-static member initializers
    std::string m_color{ "black" };
    double m_radius{ 10.0 };

public:
    // Constructor with only radius parameter (color will use default value)
    Ball(double radius)
        : m_radius{ radius }
    {
    }

    // Constructor with both color and radius parameters
    Ball(std::string_view color ="black", double radius=10.0)
        : m_color{ color }, m_radius{ radius }
    {
    }


    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
    Ball def;
    def.print();

    Ball blue{ "blue" };
    blue.print();

    Ball twenty{ 20.0 };
    twenty.print();

    Ball blueTwenty{ "blue", 20.0 };
    blueTwenty.print();

    return 0;
}