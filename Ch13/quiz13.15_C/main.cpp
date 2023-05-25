#include "Point3d.hpp"
#include "Vector3d.hpp"
#include <iostream>

int main()
{
    Point3d p{12,45,63};
    Vector3d v{-5,1,25};

    p.print();
    v.print();

    p.moveByVector(v);
    p.print();

    return 0;
}