#include <iostream>
using namespace std;


template <typename T>
T Add(T num1, T num2){
	return num1+num2;
}

int main(void){
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(1.1, 2.2) << endl;
	cout << Add<int>(21.1, 12.1) << endl;
	cout << Add<double>(3.14, 123.31) << endl;
	return 0;
} 