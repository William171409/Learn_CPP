#include <iostream>
class Point3d
{
    int m_x{};
    int m_y{};
    int m_z{};
public:
    void setValues(int a, int b ,int c)
    {
        m_x=a;
        m_y=b;
        m_z=c;
    }

    void print()
    {
        std::cout<<'<'<<m_x<<','<<m_y<<','<<m_z<<'>'<<'\n';
    }
    bool isEqual(const Point3d& p)
    {
        return ((p.m_x==m_x)&&(p.m_z==m_z)&&(p.m_y==m_y));
    }


};

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}