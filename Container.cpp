#include "Container.h"
void Container::add() {
	int i;
	cin >> i;
	switch (i) {
	case 1: {
		cout << "Please input the coodinate" << endl;
		double x, y, z, pro;
		cin >> x >> y >> z;
		Point po1(x, y, z);
		cout << "Please input the profit" << endl;
		cin >> pro;
		po1.setprofit(pro);
		Obj.push_back(&po1);
		break;
	}
	case 2: {
		cout << "Please input the edgecoodinate of a line " << endl;
		double x1, y1, z1, x2, y2, z2, pro;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		Line line(x1, y1, z1, x2, y2, z2);
		cout << "Please input the profit" << endl;
		cin >> pro;
		line.setprofit(pro);
		Obj.push_back(&line);
		break;
	}
	case 3: {
		cout << "Please input the coodinate of a circle and the radius ,as well a vector " << endl;
		double x, y, z, radius, pro, x1, y1, z1, x2, y2, z2;
		cin >> x >> y >> z >> radius >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		Circle cir(x, y, z, radius, Vector(x1, y1, z1, x2, y2, z2));
		cout << "Please input the profit" << endl;
		cin >> pro;
		cir.setprofit(pro);
		Obj.push_back(&cir);
		break;
	}
	case 4: {
		cout << "Please input the coodinate of the circle of a cylinder,eht radius and the vector of the circle as well the vector of the cylinder height" << endl;
		double x, y, z, pro, radius, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, height;
		cin >> x >> y >> z >> radius >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4 >> height;
		Cylinder cylinder(Circle(x, y, z, radius, Vector(x1, y1, z1, x2, y2, z2)), radius, Vector(x3, y3, z3, x4, y4, z4));
		cout << "Please input the profit" << endl;
		cin >> pro;
		cylinder.setprofit(pro);
		Obj.push_back(&cylinder);
		break;
	}
	case 5: {
		cout << "Please input the coodinate of a square (leftup leftdown and rightdown) " << endl;
		double x3, y3, z3, pro, x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
		Square squ(Point(x1, y1, z1), Point(x2, y2, z2), Point(x3, y3, z3));
		cout << "Please input the profit" << endl;
		cin >> pro;
		squ.setprofit(pro);
		Obj.push_back(&squ);
		break;
	}
	case 6: {
		cout << "Please input the coodinate of a rectangle(leftup leftdown and rightdown) " << endl;
		double x3, y3, z3, pro, x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
		Rectangle rec(Point(x1, y1, z1), Point(x2, y2, z2), Point(x3, y3, z3));
		cout << "Please input the profit" << endl;
		cin >> pro;
		rec.setprofit(pro);
		Obj.push_back(&rec);
		break;
	}
	case 7: {
		cout << "Please input the coodinate of a square(leftup leftdown and rightdown)of a cube and its vector " << endl;
		double x, y, z, pro, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
		cin >> x >> y >> z >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
		Cube cube(Square(Point(x, y, z), Point(x1, y1, z1), Point(x2, y2, z2)), Vector(x3, y3, z3, x4, y4, z4));
		cout << "Please input the profit" << endl;
		cin >> pro;
		cube.setprofit(pro);
		Obj.push_back(&cube);
		break;
	}
	case 8: {
		cout << "Please input the coodinate of a rectangle(leftup leftdown and rightdown)of a cuboid and its vector " << endl;
		double x, y, z, pro, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, height;
		cin >> x >> y >> z >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> height >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
		Cuboid cuboid(Point(x, y, z), Point(x1, y1, z1), Point(x2, y2, z2), height, Vector(x3, y3, z3, x4, y4, z4));
		cout << "Please input the profit" << endl;
		cin >> pro;
		cuboid.setprofit(pro);
		Obj.push_back(&cuboid);
		break;
	}
	}
}
void Container::move(double a, double b, double c){
	cout << "Please input the iterater of objects that you want to move" << endl;
	unsigned int i;
	cin >> i;
	Obj[a]->move(a,b,c);
	}
void Container::zoomin(unsigned int times) {
	cout << "Please input the iterater of objects that you want to move" << endl;
	unsigned int a;
	cin >> a;
	Obj[a]->zoomin(times);
}
void Container::zoomout(unsigned int times) {
	cout << "Please input the iterater of objects that you want to move" << endl;
	unsigned int a;
	cin >> a;
	Obj[a]->zoomout(times);
}
void Container::remove() {
	cout << "which one do you want to remove" << endl;
	unsigned int a;
	cin >> a;
	for (vector<Objects*>::iterator iter = Obj.begin(); iter != Obj.end();) {
		if ((*iter)->getid() == a) {
			iter = Obj.erase(iter);
		}
		else {
			iter++;
		}
}
}
Objects* &Container::operator[](int i) {
	if (i < 0 || i >= Obj.size())
		cout << "Out of range" << endl;
	else return Obj[i];
}
int Container::compare()const {
	cout << "Please input the id that you want to compare" << endl;
	unsigned int a, b;
	cin >> a >> b;
	if (Obj[a]->getvolume() != 0.&&Obj[a]->getvolume() != 0) {
		if (Obj[a]->getvolume() > Obj[b]->getvolume())
			return 1;
		else if (Obj[a]->getvolume() == Obj[b]->getvolume())
			return -1;
		else
			return 0;
	}
	else if (Obj[a]->getvolume() == 0.&&Obj[b]->getvolume() == 0.) {
		if (Obj[a]->getarea() != 0.&&Obj[b]->getarea() != 0) {
			if (Obj[a]->getarea() > Obj[b]->getarea())
				return 1;
			else if (Obj[a]->getarea() == Obj[b]->getarea())
				return 0;
			else return -1;
		}
		else if (Obj[a]->getarea() == 0 && Obj[b]->getarea() == 0){
			if (Obj[a]->getlength() > Obj[b]->getlength())
				return 1;
			else if (Obj[a]->getlength() == Obj[b]->getlength())
				return 0;
			else return -1;
	}
	else {
		if (Obj[b]->getarea() == 0)
			return 1;
		else return -1;
	}
}
  else {
	  if (Obj[b]->getvolume() == 0)
		  return 1;
	  else return -1;
  }
}
void Container::print()const {
	cout << "Print all or single,all-1,single-2" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		for (int i = 0; i < Obj.size(); i++) {
			Obj[i]->print();
		}
	}
	else if (a == 2) {
		cout << "Please input the number you want to print" << endl;
		int b;
		cin >> b;
		Obj[b]->print();
	}
	else cout << "Error" << endl;
}