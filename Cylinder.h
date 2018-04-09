#pragma once
#include "Circle.h"
class Cylinder:public Circle{
private:
	Vector m_vector;
	double m_height;
	double m_volume;
public:
	virtual ~Cylinder();
	Cylinder(Circle bottom, double height,Vector vector);
	Cylinder(double x, double y, double z, double radius,Vector circlevector,double height,Vector vector);
	Cylinder(const Cylinder& cylinder);
	const double getheight()const;
	const double getvolume()const;
	const double getlength()const;
	const double getarea()const;
	const Vector getvector()const;
	void move(double x, double y, double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};