#include <iostream>
#include <Point.h>
using namespace std;

Point::Point(int x, int y) : xpos(x), ypos(y) {}

void Point::ShowPosition() const {
    cout << "[" << xpos << ", " << ypos << "]" << endl;
}

ostream& Point::operator<<(ostream &os, const Point &pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
	return os;
}