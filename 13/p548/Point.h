#ifndef __POINT_H__
#define __POINT_H__

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	void ShowPosition();
	friend ostream &operator<<(ostream &os, const Point &pos);
};


#endif