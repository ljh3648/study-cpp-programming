#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "main.h"
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray {
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	// BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray &arr) {}
	// BoundCheckAccountPtrArray &operator=(const BoundCheckAccountPtrArray &arr) {}
public:
	BoundCheckAccountPtrArray(int len) : arrlen(len) {
		arr = new ACCOUNT_PTR[len];
	}
	ACCOUNT_PTR &operator[](int idx) { // [] 연산자
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exceptiton" << endl;
			exit(1);
		}
		return arr[idx];
	}
	ACCOUNT_PTR &operator[](int idx) const { // const [] 연산자 
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exceptiton" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const {
		return arrlen;
	}
	~BoundCheckAccountPtrArray() {
		delete[]arr;
	}
};

#endif