#include <iostream>
using namespace std;

class Base {
private:
	int num1;
protected:
	int num2;
	void helloProtected(){
		cout << "hello! protected" << endl;
	}
public:
	int num3;
	Base()
		: num1(1), num2(2), num3(3) {
	}
};

class Derived : protected Base {
public:
	void hello(){
		helloProtected();
	}
};

int main(void){
	Derived drv;
	// cout << drv.num3 << endl; // 컴파일 오류 발생!
	drv.hello();
	// drv.helloProtected(); // 컴파일 오류 발생!
	return 0;
}