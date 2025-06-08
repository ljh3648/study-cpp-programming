#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker {
private:
	char name[100];
	int salary;
public:
	PermanentWorker(const char *name, int money)
		:salary(money) {
		strcpy(this->name, name);
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	PermanentWorker *empList[50];
	int empNum;
public:
	EmployeeHandler()
		: empNum(0) {
	}
	void AddEmployee(PermanentWorker *emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main(void) {
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("KIM", 1000)); // 문자열 상수를 넘기는데 이는 const char*로 간주됨 하지만
	handler.AddEmployee(new PermanentWorker("Lee", 1500)); // 생성자에 입력 받는 인자형은 char *형이기 때문에 문자열 상수를
	handler.AddEmployee(new PermanentWorker("JUN", 2000)); // 수정할 수 있을 수 있는 오류가 발생하기에 인자형은 const char*가 되어야함.

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
	return 0;
}