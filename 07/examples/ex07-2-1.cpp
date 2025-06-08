#include <iostream>
using namespace std;

class Rectangle {
private:
	int height;
	int width;
public:
	Rectangle(int h, int w)
		:height(h), width(w) {
	}
	void ShowAreaInfo(){
		cout << "면적: " << height * width << endl;
	}
};

class Square : public Rectangle {
private:
	int sideLength;
public:
	Square(int sideLength)
		: Rectangle(sideLength, sideLength) {
		this->sideLength = sideLength;
	}
};

int main(void) {
	Rectangle rec(3, 4);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}