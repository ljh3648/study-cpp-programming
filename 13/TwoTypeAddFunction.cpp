#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) {
	cout << "Add(T num1, T num2) called." << endl;
	return num1 + num2;
}

int Add(int num1, int num2){
	cout << "Add(int num1, int num2) called." << endl;
	return num1 + num2;
}

double Add(double num1, double num2){
	cout << "Add(double num1, double2 num2) called." << endl;
	return num1 + num2;
}

int main(void) {
	cout << Add(5, 7) << endl;
	cout << Add(3.7, 32.1) << endl;
	cout << Add<int>(5, 7) << endl;
	cout << Add<double>(5.23, 12.6) << endl;
	return 0;
}