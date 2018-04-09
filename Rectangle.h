#pragma once
#include "Vector.h"
class Rectangle:public Objects{
protected:
	Point m_barycenter;
    Point m_left_up,m_left_down,m_right_down;
	double m_width,m_heigth;
	double m_area;
public:
	virtual ~Rectangle();
	Rectangle(Point leftup,Point leftdown,Point rightdown);
	Rectangle(const Rectangle &rectangle);
	const double getarea()const;
	const double getlength()const;
	const double getwidth()const;
	const double getheight()const;
	const double getvolume()const;
	const Point getbarycenter()const;
	void move(double x, double y, double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};