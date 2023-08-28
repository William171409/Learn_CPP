#include <iostream>
#include <string_view>

class Ball
{
    std::string_view m_color{};
    double m_radius{};

public:

    Ball(std::string_view color="black", double radius=10.0)
    {
        m_color = color;
        m_radius = radius;
    }
    Ball(double radius)
    {
        m_color="black";
        m_radius = radius;
    }

    void print()
    {
        std::cout << "Color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    return 0;
}