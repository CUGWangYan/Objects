#include "Cube.h"
Cube::~Cube() {};
Cube::Cube(Square square,Vector vector):Square(square), m_a(square.geta()), m_volume(pow(m_a, 3)),m_vector(vector) {
	if (vector*Vector(m_left_down, m_right_down) != 0 && vector*Vector(m_left_down, m_left_up) != 0) {
		cout << "Warning:This is no a Cube" << endl;
	};
};
Cube::Cube(const Cube&cube) :Square(cube), m_a(cube.m_a), m_volume(cube.m_volume),m_vector(cube.m_vector) {};
const double Cube::getvolume()const {
	return this->m_volume;
}
const double Cube::getarea()const {
	return 0.;
}
const double Cube::getlength()const {
	return 0.;
}
const double Cube::geta()const {
	return this->m_a;
}
const Vector Cube::getvector()const {
	return this->m_vector;
}
void Cube::move(double x,double y,double z) {
	Vector direct(x, y, z, this->getbarycenter().getx(), getbarycenter().gety(), getbarycenter().getz());
	this->m_barycenter += direct;
	m_left_down += direct;
	m_left_up += direct;
	m_right_down += direct;
}
void Cube::zoomin(unsigned int times) {
	Vector direct1(m_left_down,m_barycenter);
	m_left_down = times*direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times*direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times*direct3;
	m_a *= times;
	m_volume *= (times*times*times);
}
void Cube::zoomout(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times/direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times/direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times/direct3;
	m_a /= times;
	m_volume /= (times*times);
}
void Cube::print()const {
	cout << "The volume of this cube is" << getvolume() << endl;
	cout << "The right down point of this cube is (" << m_right_down.getx() << "," << m_right_down.gety() << "," << m_right_down.getz() << ")" << endl;
	cout << "The left down point of this cube is (" << m_left_down.getx() << "," << m_left_down.gety() << "," << m_left_down.getz() << ")" << endl;
	cout << "The left up point of this cube is (" << m_left_up.getx() << "," << m_left_up.gety() << "," << m_left_up.getz() << ")" << endl;
	cout << "The area of this cube is " << getarea() << endl;
	cout << "The length of this cube is" << geta() << endl;
	cout << "The volume of this cube is" << getvolume() << endl;
}