#include <iostream>
#include <string>
#include <string_view>

enum class Color
{
    red,
    green,
    blue,
    black,
    white,
    yellow,
    magenta,
    purple,
    orange,
    max_color,
};
std::string_view colorSwitch(int color)
{
    switch (color)
    {
    case 0:
        return "red";
    case 1:
        return "green";
    case 2:
        return "blue";
    case 3:
        return "black";
    case 4:
        return "white";
    case 5:
        return "yellow";
    case 6:
        return "magenta";
    case 7:
        return "purple";
    case 8:
        return "orange";
    default:
        return "???";
    }
}
class Fruit
{
    std::string m_name{};
    Color m_color{};

public:
    Fruit(std::string_view name = "", Color color = static_cast<Color>(0)) : m_name{name}, m_color{color}
    {
    }
    const std::string &getName() const { return m_name; }
    Color getColor() const { return m_color; }
};

class Apple : public Fruit
{
    double m_fiber{};

public:
    Apple(std::string_view name = "", Color color = static_cast<Color>(0), double fiber = 0.0)
        : Fruit(name, color), m_fiber{fiber}
    {
    }
    double getFiber() const { return m_fiber; }
};

std::ostream &operator<<(std::ostream &out, const Apple &a)
{
    out << "Apple(" << a.getName() << ", " << colorSwitch(static_cast<int>(a.getColor())) << ", " << a.getFiber() << ')';
    return out;
}

class Banana : public Fruit
{
public:
    Banana(std::string_view name = "", Color color = static_cast<Color>(0))
        : Fruit(name, color)
    {
    }
};

std::ostream &operator<<(std::ostream &out, const Banana &b)
{
    out << "Banana(" << b.getName() << ", " << colorSwitch(static_cast<int>(b.getColor())) << ')';
    return out;
}

int main()
{
    const Apple a{"Red delicious", Color::red, 4.2};
    std::cout << a << '\n';

    const Banana b{"Cavendish", Color::yellow};
    std::cout << b << '\n';

    return 0;
}