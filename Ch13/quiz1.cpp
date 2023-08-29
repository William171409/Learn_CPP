#include <iostream>
#include <cmath>

class Point2d
{
    double m_x{};
    double m_y{};
public:
    Point2d(double x=0 , double y=0):m_x{x},m_y{y}
    {}
    void print ()const
    {
        std::cout<<"Point2d("<<m_x<<", "<<m_y<<")\n";
    }

    // One nuance of C++ that is often missed or misunderstood is that 
    // access control works on a per-class basis, not a per-object basis. 
    // This means that when a function has access to the private members of a class, 
    // it can access the private members of any object of that class type that it 
    // can see.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // double distanceTo (const Point2d& p)const
    // {
    //     return std::sqrt(pow(p.m_x-m_x,2)+pow(p.m_y-m_y,2));
    // }
    friend double distanceBetween(const Point2d& p1,const Point2d& p2);
};
double distanceBetween(const Point2d& p1,const Point2d& p2)
{
    // p1.print();
    // p2.print();
    return std::sqrt(pow(p1.m_x-p2.m_x,2)+pow(p1.m_y-p2.m_y,2));
}
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 5.0 };
    // first.print();
    // second.print();
    std::cout << "Distance between two points: " << distanceBetween(first,second) << '\n';

    return 0;
}