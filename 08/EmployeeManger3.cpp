#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(const char *name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(const char *name, int money)
		: Employee(name), salary(money) {
	}
	int GetPay() const {
		cout << "PermanentWorker: GetPay() called." << endl;
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char *name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {
	}
	void AddSalesResult(int value){
		salesResult += value;
	}
	int GetPay() const{
		cout << "SalesWorker: GetPay() called." << endl;
		return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {
	}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};


class EmployeeHandler {
private:
	Employee *empList[50];
	int empNum;
public:
	EmployeeHandler()
		: empNum(0) {
	}
	void AddEmployee(Employee *emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		// for (int i = 0; i < empNum; i++) {
		// 	empList[i]->ShowSalaryInfo();
		// }
	}
	void ShowTotalSalary() const {
		int sum = 0;
		// for (int i = 0; i < empNum; i++) {
		// 	sum += empList[i]->GetPay();
		// }
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

	handler.AddEmployee(new PermanentWorker("KIM", 1000)); 
	handler.AddEmployee(new PermanentWorker("Lee", 1500)); 

	TemporaryWorker *alba=new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	// SalesWorker test1("Lee", 2000, (double)1.1);
	// test1.GetPay();
	// test1.PermanentWorker::GetPay();
	return 0;
}

//오버로딩은 전달하는 인자나 반환하는 형이 다를때 오버로딩또는 오버로드라고 부르는데
//오버라이딩은 재정의해서 이전에 선언된 함수가 숨김처리 되는거 같은 느낌