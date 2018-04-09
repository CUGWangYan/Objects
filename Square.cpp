#include "Square.h"
Square::~Square(){};
Square::Square(Point leftup, Point leftdown, Point rightdown):Objects(),m_left_down(leftdown),m_left_up(leftup),m_right_down(rightdown),m_a(pow(pow(leftup.getx() - leftdown.getx(), 2) + pow(leftup.gety() - leftdown.gety(), 2) + pow(leftup.getz() - leftdown.getz(), 2), 0.5)),m_area(m_a*m_a),m_barycenter((m_left_up.getx() + m_right_down.getx()) / 2, (m_left_up.gety() + m_right_down.gety()) / 2, (m_left_up.getz() + m_right_down.getz()) / 2) {
	Vector vec1(leftup, leftdown);
	Vector vec2(leftdown, rightdown);
	if (vec1*vec2 != 0.&&vec1.length()!=vec2.length()) {
		cout << "ERROR" << endl;
	}
};
Square::Square(const Square&square) 
	:Objects(square), m_left_up(square.m_left_up), m_left_down(square.m_left_down), m_right_down(square.m_right_down), m_area(square.m_area), m_a(square.m_a),m_barycenter(square.m_barycenter) { };
const double Square::getarea()const {
	return this->m_area;
}
const double Square::getvolume()const {
	return 0.;
}
const double Square::getlength()const {
	return 0.;
}
const double Square::geta()const {
	return this->m_a;
}
const Point Square::getbarycenter()const {
	return  m_barycenter;
}
void Square::zoomin(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times*direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times*direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times*direct3;
	m_a *= times;
	m_area *= (times*times);
}
void Square::zoomout(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times/direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times/direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times/direct3;
	m_a /= times;
	m_area /= (times*times);
}
void Square::move(double x, double y, double z) {
	Vector direct(x, y, z, this->getbarycenter().getx(), getbarycenter().gety(), getbarycenter().getz());
	this->m_barycenter += direct;
	m_left_down += direct;
	m_left_up += direct;
	m_right_down += direct;
}
void Square::print()const {
	cout << "The right down point of this square is (" << m_right_down.getx() << "," << m_right_down.gety() << "," << m_right_down.getz() << ")" << endl;
	cout << "The left down point of this square is (" << m_left_down.getx() << "," << m_left_down.gety() << "," << m_left_down.getz() << ")" << endl;
	cout << "The left up point of this square is (" << m_left_up.getx() << "," << m_left_up.gety() << "," << m_left_up.getz() << ")" << endl;
	cout << "The area of this square is " << getarea() << endl;
	cout << "The length of this square is" << getlength() << endl;
}