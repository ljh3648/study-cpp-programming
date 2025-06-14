#include "Point.h"

Point::Point(int x, int y) : xpos(x), ypos(y) {}

void Point::ShowPosition() const {
    std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Point &pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << std::endl;
	return os;
}