#include "Circle.h"
Circle::~Circle() {};
Circle::Circle(Vector vector,double radius) :Point(),m_vector(vector),m_radius(radius), m_area(radius*radius*PI) {};
Circle::Circle(const Circle&circle) :Point(circle),m_radius(circle.m_radius), m_area(circle.m_area),m_vector(circle.m_vector) {};
Circle::Circle(double x, double y, double z, double radius,Vector vector):Point(x, y, z), m_radius(radius), m_area(radius*radius*PI),m_vector(vector) {};
const double Circle::getarea()const {
	return m_area;
};
const double Circle::getradius()const {
	return m_radius;
}
const double Circle::getvolume()const {
	cout << "Circle has no volume" << endl;
	return 0.;
}
const double Circle::getlength()const{
	return 0.;
}
const Vector Circle::getvector()const {
	return m_vector;
}
void Circle::move(double x,double y,double z) {
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}
void Circle::zoomin(unsigned int times) {
	this->m_radius *= times;
}
void Circle::zoomout(unsigned int times) {
	this->m_radius /= times;
}
void Circle::print()const {
	cout << "The radius of this circle is"<<m_radius << endl;
	cout << "The point of this circle is (" << m_x << "," << m_y << "," << m_z << ")" << endl;
	cout << "The area of this circle is " << getarea() << endl;
}
