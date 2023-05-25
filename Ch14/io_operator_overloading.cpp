#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
      : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

// The trickiest part here is the return type. With the arithmetic operators, 
// we calculated and returned a single answer by value (because we were creating and 
// returning a new result). However, if you try to return std::ostream by value, 
// you’ll get a compiler error. This happens because std::ostream specifically 
// disallows being copied.

//Additionally, out is an object of class std::ostream and out<<....... statement
//will modify the state of it. Hence, we cant pass by const reference!
std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')'; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}

int main()
{
    const Point point1{2.0, 3.8, 4.0};

    std::cout << point1 << '\n';

    return 0;
}