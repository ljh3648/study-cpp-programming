#include <iostream>
#include <cstring>
using namespace std;

class BoundCheckIntArray {
private:
	int *arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len) { // 생성자 정의
		arr = new int[len];
	}
	int &operator[](int idx) { // []연산자 정의로 배열 경계선 정의 가능함.
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exceptiton" << endl;
			exit(1);
		}
		return arr[idx];
	}
	~BoundCheckIntArray() { // 소멸자 정의
		delete[]arr;
	}
};


int main(void) {
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}