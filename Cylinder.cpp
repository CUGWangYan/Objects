#include "Cylinder.h"
Cylinder::~Cylinder() {};
Cylinder::Cylinder(Circle bottom, double height,Vector vector):Circle(bottom),m_height(height),m_volume(getarea()*m_height),m_vector(vector){
	if (!(vector==bottom.getvector()) && !(vector==bottom.getvector())) {
		cout << "Warning:This is no a zheng cylinder" << endl;
	};
};
Cylinder::Cylinder(double x, double y, double z, double radius,Vector circlevector, double height,Vector vector)
	:Circle(x, y, z, radius,circlevector), m_height(height),m_volume(getarea()*m_height),m_vector(vector) {};
Cylinder::Cylinder(const Cylinder&cylinder) 
	:Circle(cylinder),m_height(cylinder.m_height),m_volume(cylinder.m_volume),m_vector(cylinder.m_vector){};
const double Cylinder::getheight()const {
	return this->m_height;
}
const double Cylinder::getvolume()const {
	return getarea()*this->m_height;
}
const Vector Cylinder::getvector()const {
	return this->getvector();
};
const double Cylinder::getlength()const {
	return 0.;
}
const double Cylinder::getarea()const {
	return 0.;
}
void Cylinder::move(double x, double y, double z) {
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}
void Cylinder::zoomin(unsigned int times){
	this->m_radius *= times;
	m_volume *= times;
}
void Cylinder::zoomout(unsigned int times) {
	this->m_radius /= times;
	m_volume /= times;
}
void Cylinder::print()const {
	cout << "The volume of this cylinder is" << getvolume() << endl;
	cout << "The  point of this cylinder is (" << m_x << "," << m_y << "," << m_z << ")" << endl;
	cout << "The height of this cube is" << getheight() << endl;
	cout << "The volume of this cube is" << getvolume() << endl;
}