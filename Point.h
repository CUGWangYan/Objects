#pragma once
#include "Objects.h"
class Point:public Objects{
protected:
	double  m_x, m_y, m_z;
public:
	Point(double a = 0.,double b = 0.,double c = 0.);
	virtual ~Point();
	Point(const Point &point);
	const double getx()const;
	const double gety()const;
	const double getz()const;
	const double getarea()const;
	const double getlength()const;
	const double getvolume()const;
	void reset(double x, double y, double z);
	void move(double x, double y, double z);
	void print()const;
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
};