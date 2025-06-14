#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

};

template <typename T>
void SwapData(T *num1, T *num2) {
	T temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(void) {
	Point a1(1, 2);
	Point a2(3, 4);

	SwapData<Point>(&a1, &a2);
	
	a1.ShowPosition();
	a2.ShowPosition();
	return 0;
}