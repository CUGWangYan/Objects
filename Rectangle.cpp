#include "Rectangle.h"
Rectangle::~Rectangle() {};
Rectangle::Rectangle(Point leftup,Point leftdown, Point rightdown) 
	:m_left_up(leftup), m_right_down(rightdown),m_left_down(leftdown),m_barycenter((leftup.getx()+rightdown.getx())/2, (leftup.gety() + rightdown.gety())/2,(leftup.getz() + rightdown.getz() / 2)),m_width(pow(pow(leftup.getx()-leftdown.getx(),2)+pow(leftup.gety()-leftdown.gety(),2) + pow(leftup.getz() - leftdown.getz(), 2),0.5)),m_heigth(pow(pow(rightdown.getx() - leftdown.getx(), 2) + pow(rightdown.gety() - leftdown.gety(), 2) + pow(rightdown.getz() - leftdown.getz(), 2), 0.5)),m_area(m_width*m_heigth){};
Rectangle::Rectangle(const Rectangle&ractangle) 
	:Objects(ractangle), m_left_up(ractangle.m_left_up), m_left_down(ractangle.m_left_down), m_right_down(ractangle.m_right_down),m_barycenter(ractangle.m_barycenter),m_width(ractangle.m_width), m_heigth(ractangle.m_heigth), m_area(ractangle.m_area) {};
const double Rectangle::getarea()const {
	return this->m_area;
}
const double Rectangle::getvolume()const {
	return 0.;
}
const double Rectangle::getheight()const {
	return this->m_heigth;
}
const double Rectangle::getlength()const {
	return 0.;
}
const double Rectangle::getwidth()const {
	return this->m_width;
}
const Point Rectangle::getbarycenter()const {
	return m_barycenter;
}
void Rectangle::move(double x,double y,double z) {
	Vector direct(x, y, z, this->getbarycenter().getx(), getbarycenter().gety(), getbarycenter().getz());
	this->m_barycenter += direct;
	m_left_down += direct;
	m_left_up += direct;
	m_right_down += direct;
}
void Rectangle::zoomin(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times*direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times*direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times*direct3;
	m_width *= times;
	m_heigth *= times;
	m_area *= (times*times);
}
void Rectangle::zoomout(unsigned int times) {
	Vector direct1(m_left_down, m_barycenter);
	m_left_down = times / direct1;
	Vector direct2(m_left_up, m_barycenter);
	m_left_up = times / direct2;
	Vector direct3(m_right_down, m_barycenter);
	m_right_down = times / direct3;
	m_width *= times;
	m_heigth *= times;
	m_area /= (times*times);
}
void Rectangle::print()const {
	cout << "The right down point of this rectangle is (" << m_right_down.getx() << "," << m_right_down.gety() << "," << m_right_down.getz() << ")" << endl;
	cout << "The left down point of this rectangle is (" << m_left_down.getx() << "," << m_left_down.gety() << "," << m_left_down.getz() << ")" << endl;
	cout << "The left up point of this rectangle is (" << m_left_up.getx() << "," << m_left_up.gety() << "," << m_left_up.getz() << ")" << endl;
	cout << "The area of this rectangle is " << getarea() << endl;
	cout << "The width of this rectangle is" << getwidth() << endl;
	cout << "The lenght of this rectangle is " << getheight() << endl;
}
