#pragma once
#include "Rectangle.h"
class Cuboid :public Rectangle{
private:
	Vector m_vector;
	double m_height;
	double m_volume;
public:
	virtual ~Cuboid();
	Cuboid(Point leftup, Point leftdown, Point rightdown, double height,Vector vector);
	Cuboid(const Cuboid& cuboid);
	const double getvolume()const;
	const double getarea()const;
	const double getlength()const;
	const double getheight()const;
	const Vector getvector()const;
	void move(double x, double y, double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};