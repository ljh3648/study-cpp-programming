#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	void ShowPosition() const;
	friend std::ostream& operator<<(std::ostream &os, const Point &pos);
	
};


#endif