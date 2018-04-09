#pragma once
#include "Square.h"
class Cube :public Square{
private:
	Vector m_vector;
	double m_a;
	double m_volume;
public:
	virtual ~Cube();
	Cube(Square square,Vector vector);
	Cube(const Cube&cube);
	const double getvolume()const;
	const double getlength()const;
	const double geta()const;
	const double getarea()const;
	const Vector getvector()const;
	void move(double x,double y,double z);
	void zoomin(unsigned int times);
	void zoomout(unsigned int times);
	void print()const;
};