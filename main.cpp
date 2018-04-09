#include "Container.h"
using namespace std;
int main() {
    Container container;
	cout << "Which objtct do you want to add 1-point,2-line,3-circlce,4-cylinder,5-square,6-rectangle,7-cube,8-cuboid" << endl;
	container.add();		
	container.print();
	return 0;
}