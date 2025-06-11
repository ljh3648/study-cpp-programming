#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
};

bool operator==(const Point &pos1, const Point &pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) return true;
	else return false;
}

bool operator!=(const Point &pos1, const Point &pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) return false;
	else return true;
}

int main(void) {
	Point pos1(10, 20);
	Point pos2(10, 20);
	Point pos3(10, 30);

	bool flag = (pos1 == pos2);
	cout << flag << endl;

	flag = (pos1 == pos3);
	cout << flag << endl;

	flag = (pos1 != pos2);
	cout << flag << endl;

	flag = (pos1 != pos3);
	cout << flag << endl;

	return 0;
}

