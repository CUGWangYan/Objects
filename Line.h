#pragma once
#include "Vector.h"
class Line : public Objects{
private:
	Point m_A, m_B;
	Point m_barycenter;
	double m_length;
public:
	~Line();
	Line(Point a, Point b);
	Line(double x1, double y1, double z1, double x2, double y2, double z2);
	Line(const Line &line);
	const double getlength()const;
	const Point getbarycenter()const;
	const Point geta()const;
	const Point getb()const;
	const double getarea()const;
	const double getvolume()const;
	void move(double x, double y, double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};