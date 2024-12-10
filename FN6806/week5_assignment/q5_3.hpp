#pragma once
#include <tuple>
#include <vector>
#include <memory>
#include <utility>
#include <cassert>
using namespace std;

class Coord
{
    double _x;
    double _y;

public:
    Coord() : Coord(0, 0) {}
    Coord(double x, double y) : _x(x), _y(y) {}

    bool operator==(const Coord &rhs) const
    {
        return _x == rhs.get_x() && _y == rhs.get_y();
    }

    void set_x(double x) { _x = x; }
    void set_y(double y) { _y = y; }
    double get_x() const { return _x; }
    double get_y() const { return _y; }

    Coord operator+(const Coord &p) const { return Coord(_x + p.get_x(), _y + p.get_y()); }
    Coord &operator+=(const Coord &rhs)
    {
        _x += rhs.get_x();
        _y += rhs.get_y();
        return *this;
    }
};

class Shape
{
protected:
    Coord anchorPoint;

public:
    Shape(const Coord &p) : anchorPoint(p) {}
    virtual ~Shape() = default;
    virtual Shape &move(const Coord &offset) = 0;
    const Coord& getAnchorPoint() const {
        return anchorPoint;
    }
    
};

class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(const Coord &p, double w, double h) : Shape(p), width(w), height(h) {}
    virtual Rectangle &move(const Coord &offset) override { anchorPoint += offset; return *this; }

    friend ostream &operator<<(ostream &os, const Rectangle &rectangle);
};

class Circle : public Shape
{
    double radius;

public:
    Circle(const Coord &p, double r) : Shape(p), radius(r) {}
    virtual Circle &move(const Coord &offset) override { anchorPoint += offset; return *this; }

    friend ostream &operator<<(ostream &os, const Circle &circle);
};

class ShapeCollection : public Shape
{
protected:
    vector<unique_ptr<Shape>> elements; 

public:
    ShapeCollection() : Shape(Coord(0, 0)) {}

    ShapeCollection(unique_ptr<Shape> S) : Shape(Coord(0, 0))
    {
        add(std::move(S));
    }

    ShapeCollection &add(unique_ptr<Shape> S); 
    ShapeCollection &remove(size_t i); 
    size_t size() const { return elements.size(); } 
    ShapeCollection &move(const Coord &offset) override; 

    friend ostream &operator<<(ostream &os, const ShapeCollection &shapeCollection);
};


void q5_3(void);
void testCoord(void);
void testRectangle(void);
void testCircle(void);
void testShapeCollection(void);



