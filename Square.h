#pragma once
#include "Vector.h"
class Square :public Objects{
protected:
	Point m_barycenter;
    Point m_left_up, m_left_down, m_right_down;
    double m_area;
	double m_a;
public:
	virtual ~Square();
	Square(Point leftup,Point leftdown,Point rightdown);
	Square(const Square &square);
	const double getarea()const;
	const double getvolume()const;
	const double getlength()const;
	const double geta()const;
	const Point getbarycenter()const;
	void move(double x, double y, double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};