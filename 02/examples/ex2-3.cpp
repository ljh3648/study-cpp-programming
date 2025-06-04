#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2) {
	Point *ptr = new Point{(p1.xpos + p2.xpos), (p1.ypos + p2.ypos)};
	return *ptr;
}

int main(void) {
	Point *p1 = new Point{ 1,2 };
	Point *p2 = new Point{ 2,3 };

	Point &value = PntAdder(*p1, *p2);

	cout << value.xpos << ", " << value.ypos << endl;
	return 0;
}