#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	void Init(int x, int y, int r) {
		center.Init(x, y);
		radius = r;
	}
	void ShowCenterPos() const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle c_inner, c_outter;
public:
	void Init(int c_inner_x, int c_inner_y, int c_inner_r, int c_outter_x, int c_outter_y, int c_outter_r) {
		c_inner.Init(c_inner_x, c_inner_y, c_inner_r);
		c_outter.Init(c_outter_x, c_outter_y, c_outter_r);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info..." << endl;
		c_inner.ShowCenterPos();
		cout << "Outter Circle Info..." << endl;
		c_outter.ShowCenterPos();
	}
};

int main(void) {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}