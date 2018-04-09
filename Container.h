#pragma once
#include "Cylinder.h"
#include "Cuboid.h"
#include "Cube.h"
#include "Line.h"
#include <vector>
class Container {
private:
	vector<Objects*>Obj;
public:
	void add();
	void move(double,double,double);
	void zoomin(unsigned int);
	void zoomout(unsigned int);
	int compare()const;
	void print()const;
	void remove();
	Objects* &operator[](int);
};