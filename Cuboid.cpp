#include "Cuboid.h"
Cuboid::~Cuboid() {};
Cuboid::Cuboid(Point leftup, Point leftdown, Point rightdown, double height,Vector vector)
	:Rectangle(leftup, leftdown, rightdown), m_height(height),m_volume(height*getarea()),m_vector(vector) {
	if (vector*Vector(m_left_down, m_right_down) != 0 && vector*Vector(m_left_down, m_left_up) != 0) {
		cout << "Warning:This is no a cuboid" << endl;
	};
};
Cuboid::Cuboid(const Cuboid&cuboid) 
	:Rectangle(cuboid), m_height(cuboid.m_height),m_volume(cuboid.m_volume),m_vector(cuboid.m_vector){};
const double Cuboid::getvolume()const {
	return this->m_volume;
}
const double Cuboid::getarea()const {
	return 0.;
}
const double Cuboid::getlength()const {
	return 0.;
}
const double Cuboid::getheight()const {
	return this->m_height;
}
const Vector Cuboid::getvector()const {
	return this->m_vector;
}
void Cuboid::zoomin(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times*direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times*direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times*direct3;
	m_width *= times;
	m_heigth *= times;
	m_height *= times;
	m_volume *= (times*times*times);
}
void Cuboid::zoomout(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times/direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times/direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times/direct3;
	m_width /= times;
	m_heigth /= times;
	m_height /= times;
	m_volume /= (times*times*times);
}
void Cuboid::move(double x, double y, double z) {
	Vector direct(x, y, z, this->getbarycenter().getx(), getbarycenter().gety(), getbarycenter().getz());
	this->m_barycenter += direct;
	m_left_down += direct;
	m_left_up += direct;
	m_right_down += direct;
}
void Cuboid::print()const {
	cout << "The volume of this cuboid is" << getvolume() << endl;
	cout << "The right down point of this cuboid is (" << m_right_down.getx() << "," << m_right_down.gety() << "," << m_right_down.getz() << ")" << endl;
	cout << "The left down point of this cuboid is (" << m_left_down.getx() << "," << m_left_down.gety() << "," << m_left_down.getz() << ")" << endl;
	cout << "The left up point of this cuboid is (" << m_left_up.getx() << "," << m_left_up.gety() << "," << m_left_up.getz() << ")" << endl;
	cout << "The area of this cuboid is " << getarea() << endl;
	cout << "The length of this cuboid is" << getlength() << endl;
	cout << "The width of this cuboid is" << getwidth() << endl;
	cout << "The volume of this cube is" << getvolume() << endl;
}