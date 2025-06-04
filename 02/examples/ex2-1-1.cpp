#include <iostream>
using namespace std;

void IntPlus(int &num) {
	num++;
}

void IntInvertSign(int &num) {
	num = num * -1;
}

int main(void) {
	int num = 30;
	IntPlus(num);
	cout << "num value: " << num << endl;
	IntInvertSign(num);
	cout << "num value: " << num << endl;

	return 0;
}