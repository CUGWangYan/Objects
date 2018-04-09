#pragma once
#include "Vector.h"
const double PI = 3.1415926;
class Circle:public Point{
private:
	double m_area;
    Vector m_vector;
protected:
    double m_radius;
public:
	virtual ~Circle();
	Circle(Vector vector,double radius=0.0);
	Circle(double x, double y, double z, double radius,Vector vector);
	Circle(const Circle& circle);
	const double getarea()const;
	const double getvolume()const;
	const double getradius()const;
	const double getlength()const;
	const Vector getvector()const;
	void move(double x,double y,double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};