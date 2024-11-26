#include <iostream>


class Point
{
public:
    int x{};
    int y{};

    Point():x{0},y{0}{
        std::cout<<"Default Constructor is called!\n";
    }
    Point(int x, int y=0): x{x},y{y}{
        std::cout<<"Non-default Constructor is called!\n";
    }

    Point(const Point &other) : x(other.x) {
        std::cout << "Copy Constructor is called\n";
    }

    Point &operator=(const Point p) {
        std::cout << "Copy Assignment Operator called\n";
        x = p.x;
        return *this;
    }



};


int main()
{
    Point p1;
    //Default ctor is called
    std::cout << p1.x << "\n"; // 0

    Point p2(43);
    // Non-default ctor is caled
    std::cout << p2.x << "\n"; // 43

    
    Point p3(p1);
    // Copy ctor is called
    std::cout << p3.x << "\n"; // 0
    // std::cout << p3.y << "\n"; // 0


    p3 = p2;
    // Copy Assignment ctor is called
    // When copy assignment constructor is,

    //     Point &operator=(const Point p) {
    //     std::cout << "Copy Assignment Operator called\n";
    //     x = p.x;
    //     return *this;
    // }
    
    // The copy constructor is firstly called to make an input p and then copy assignment constructor is called to pass
    // p2 to p3


    std::cout << p3.x << "\n"; // 43

    // Non-default ctor is caled
    Point p4 = Point(40);

    // Copy ctor is called
    Point p5 = p2;

    return 0;
}