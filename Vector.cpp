#include "Vector.h"
Vector::~Vector() {};
Vector::Vector(Point a, Point b) :m_head(a), m_tail(b),m_direct(a.getx()-b.getx(),a.gety()-b.gety(),a.getz()-b.getz()) {};
Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2) :m_head(x1, y1, z1), m_tail(x2, y2, z2),m_direct(x1-x2,y1-y2,z1-z2) {};
double Vector::length()const {
	return pow(pow(m_head.getx() - m_tail.getx(), 2) + pow(m_head.gety() - m_tail.gety(), 2) + pow(m_head.getz() - m_tail.getz(), 2), 0.5);
}
void Vector::setvector(Point a, Point b) {
	m_head = a;
	m_tail = b;
	m_direct = (a.getx() - b.getx(), a.gety() - b.gety(), a.getz() - b.getz());
};
void Vector::setvector(double x1, double y1, double z1, double x2, double y2, double z2) {
	m_head.reset(x1, y1, z1);
	m_tail.reset(x2, y2, z2);
	m_direct = (x1 - x2, y1 - y2, z1 - z2);
}
	Vector Vector::operator+(const Vector&vector)const{
		return Vector((m_tail.getx() + m_direct.getx() + vector.m_direct.getx(), m_tail.gety() + m_direct.gety() + vector.m_direct.gety(), m_tail.getz() + m_direct.getz() + vector.m_direct.getz()),this->m_tail);
	}
	double Vector::operator*(const Vector&vector)const {
		return this->m_direct.getx()*vector.m_direct.getx() + this->m_direct.gety()*vector.m_direct.gety() + this->m_direct.getz()*vector.m_direct.getz();
	}
	bool Vector::operator==(const Vector&vector)const {
		if (vector.m_direct.getx() / m_direct.getx() == vector.m_direct.gety() / m_direct.gety() == vector.m_direct.getz() / m_direct.getz())
			return true;
		else return false;
	};
	Vector& Vector::operator=(const Vector&vector) {
		this->m_head = vector.m_head;
		this->m_tail = vector.m_tail;
		this->m_direct = vector.m_direct;
		return *this;
	}
	Point operator+(const Point &point, const Vector&vector) {
		return Point(vector.m_direct.getx()+point.getx(), vector.m_direct.gety() + point.gety(), vector.m_direct.getz() + point.getz());
	}
	Point operator+=(Point &point, const Vector&vector) {
		point = point + vector;
		return point;
	}
	Point operator*(unsigned int times, const Vector &vector) {
		return Point(vector.m_tail.getx() + vector.m_direct.getx()*times, vector.m_tail.gety() + vector.m_direct.gety()*times, vector.m_tail.getz() + vector.m_direct.getz()*times);
	}
	Point operator/(unsigned int times, const Vector &vector) {
		return Point(vector.m_tail.getx() + vector.m_direct.getx()/times, vector.m_tail.gety() + vector.m_direct.gety()/times, vector.m_tail.getz() + vector.m_direct.getz()/times);
	}