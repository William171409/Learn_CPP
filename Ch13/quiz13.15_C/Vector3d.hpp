#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include "Point3d.hpp"
class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;
    friend void Point3d::moveByVector(const Vector3d& v);
};

#endif
