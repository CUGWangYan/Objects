#include "Point.h"
Point::Point(double a, double b, double c) :Objects(), m_x(a), m_y(b), m_z(c) {};
Point::~Point() {};
Point::Point(const Point&point) :Objects(point),m_x(point.m_x), m_y(point.m_y), m_z(point.m_z) {};
void Point::reset(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
};
const double Point::getarea()const {
	return 0.;
}
const double Point::getvolume()const {
	return 0.;
}
const double Point::getlength()const {
	return 0.;
}
const double Point::getx()const{
	return this->m_x;
}
const double Point::gety()const {
	return this->m_y;
}
const double Point::getz()const {
	return this->m_z;
}
void Point::move(double x, double y, double z) {
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}
void Point::print()const {
	cout<<"The point is ("<< m_x<<"," << m_y<<"," << m_z <<")"<< endl;
}
void Point::zoomin(unsigned int times) {
	return;
}
void Point::zoomout(unsigned int times) {
	return;
}