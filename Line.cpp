#include "Line.h"
Line::~Line() { };
Line::Line(Point a, Point b)
	:Objects(), m_A(a), m_B(b), m_length(pow(pow(a.getx() - b.getx(), 2) + pow(a.gety() - b.gety(), 2) + pow(a.getz() - b.getz(), 2), 0.5)), m_barycenter((m_A.getx() + m_B.getx()) / 2, (m_A.gety() + m_B.gety()) / 2, (m_A.getz() + m_B.getz()) / 2) {
};
Line::Line(double x1, double y1, double z1, double x2, double y2, double z2) :Objects(), m_A(x1, y1, z1), m_B(x2, y2, z2),m_length(pow(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2), 0.5)), m_barycenter((x1 + x2) / 2, (y1 + y2) / 2, (z1 +z2) / 2) {};
Line::Line(const Line&line) :Objects(),m_A(line.m_A), m_B(line.m_B), m_length(line.m_length),m_barycenter(line.m_barycenter) {};
const double Line::getlength()const{
	return this->m_length;
}
const Point Line::getbarycenter()const {
	return this->m_barycenter;
}
const Point Line::geta()const {
	return m_A;
}
const Point Line::getb()const {
	return m_B;
}
const double Line::getarea()const {
	return 0.;
}
const double Line::getvolume()const {
	return 0.;
}
void Line::zoomin(unsigned int times) {
	Vector direct1(m_A, m_barycenter);
	m_A = times*direct1;
	Vector direct2(m_B, m_barycenter);
	m_B = times*direct2;
	m_length *= times;
}
void Line::zoomout(unsigned int times) {
	Vector direct1(m_A, m_barycenter);
	m_A = times/direct1;
	Vector direct2(m_B, m_barycenter);
	m_B = times/direct2;
	m_length /= times;
}
void Line::move(double x, double y, double z) {
	Vector direct(x, y, z, this->getbarycenter().getx(), getbarycenter().gety(), getbarycenter().getz());
	this->m_barycenter += direct;
	m_A += direct;
	m_B += direct;
}
void Line::print()const {
	cout << "The point of this line is (" << m_A.getx() << "," << m_A.gety() << "," << m_A.getz() << ")" << endl;
	cout << "The point of this line is (" << m_B.getx() << "," << m_B.gety() << "," << m_B.getz() << ")" << endl;
	cout << "The length of this line is " << this->getlength() << endl;
}