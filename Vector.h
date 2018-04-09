#pragma once
#include "Point.h"
class Vector{
private:
	Point m_head;
	Point m_tail;
	Point m_direct;
public:
	~Vector();
	Vector(Point a, Point b);
	Vector(double x1, double y1, double z1, double x2, double y2, double z2);
	double length()const;
	void setvector(Point a, Point b);
	void setvector(double x1, double y1, double z1, double x2, double y2, double z2);
	Vector operator+(const Vector&vector)const;
	double operator*(const Vector&vector)const;
	Vector& operator=(const Vector&vector);
	bool operator==(const Vector&vector)const;
    friend Point operator*(unsigned int times,const Vector &vector);
	friend Point operator/(unsigned int times, const Vector &vector);
	friend Point operator+(const Point&point,const Vector&vector);
	friend Point operator+=(Point &point, const Vector&vector);
};	