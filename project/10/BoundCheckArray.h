#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include "main.h"

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
public:
	BoundCheckArray(int len) : arrlen(len) {
		arr = new T[len];
	}
	T& operator[](int idx) { // [] 연산자
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exceptiton" << endl;
			exit(1);
		}
		return arr[idx];
	}
	T& operator[](int idx) const { // const [] 연산자 
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exceptiton" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const {
		return arrlen;
	}
	~BoundCheckArray() {
		delete[]arr;
	}
};

#endif