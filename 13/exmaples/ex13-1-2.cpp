#include <iostream>
using namespace std;


template<typename T>
T SumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

int main(void) {
	int a[3] = { 1, 2, 3 };
	double b[3] = { 1.1, 2.2, 3.3 };

	cout << SumArray<int>(&a[0], 3) << endl;
	cout << SumArray<double>(&b[0], 3) << endl;
	return 0;
}