#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CUSTOMER_CNT 50
#define MAX_NAME_LEN 20

class Account {
private:
	unsigned int id;
	char *name;
	long long int balance;
public:
	Account(unsigned int id, char *name, long long int balance) {
		this->id = id;
		this->name = new char[strlen(name)];
		strcpy(this->name, name);
		this->balance = balance;
	}
	void deposit(int money) {
		this->balance += money;
	}
	int withDrawal(int money) {
		if (this->balance < money) {
			cout << "잔액 부족" << endl;
			return 1;
		}
		this->balance -= money;
		return 0;
	}
	void accountInfo() {
		cout << "계좌ID: " << this->id << endl;
		cout << "이  름: " << this->name << endl;
		cout << "잔  액: " << this->balance << endl;
		cout << endl;
	}
	unsigned int getAccountID() {
		return id;
	}
	~Account() {
		delete[]name;
	}
};

namespace Bank {
	int select;

	void showMenu(void);
	int getUserMenuSel(void);
	void newAccountCreate(void);
	void deposit(void);
	void Withdrawal(void);
	void showAllAccountInfo(void);
}

Account *customer[MAX_CUSTOMER_CNT];
int current_customer_cnt = 0;

int main(void) {
	Bank::select = 0;

	while (true) {
		Bank::showMenu();
		Bank::select = Bank::getUserMenuSel();
		// Bank::process(Bank::select);
		switch (Bank::select) {
		case 1:
			Bank::newAccountCreate();
			break;
		case 2:
			Bank::deposit();
			break;
		case 3:
			Bank::Withdrawal();
			break;
		case 4:
			Bank::showAllAccountInfo();
			break;
		case 5:
			return 0;
		default: return EOF;
		}
	}

	return 0;
}

void Bank::showMenu() {
	cout << "--------Menu--------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료 " << endl;
}

int Bank::getUserMenuSel() {
	int select = 0;

	while (true) {
		cout << "선택: ";
		cin >> select;
		if (0 < select && select < 6) {
			break;
		}
		else {
			cout << "잘못된 선택입니다." << endl;
		}
	}

	return select;
}

void Bank::newAccountCreate() {
	unsigned int id;
	char name[100];
	long long int balance;

	cout << "\n[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	cout << "이름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> balance;

	cout << endl;

	customer[current_customer_cnt] = new Account(id, name, balance);
	current_customer_cnt++;
}

void Bank::deposit() {
	unsigned int id;
	char name[100];
	long long int money;

	cout << "\n[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	for (int i = 0; i < current_customer_cnt; i++) {
		if (id == customer[i]->getAccountID()) {
			cout << "입금액: ";
			cin >> money;
			customer[i]->deposit(money);
			cout << "입금완료 " << endl;
			return;
		}
	}

	cout << "잘못된 계좌ID 입니다. " << endl;
	return;
}

void Bank::Withdrawal() {
	unsigned int id;
	char name[100];
	long long int money;

	cout << "\n[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	for (int i = 0; i < current_customer_cnt; i++) {
		if (id == customer[i]->getAccountID()) {
			cout << "출금액: ";
			cin >> money;
			customer[i]->withDrawal(money);
			cout << "출금완료 " << endl;
			return;
		}
	}

	cout << "잘못된 계좌ID 입니다. " << endl;
	return;
}

void Bank::showAllAccountInfo() {
	cout << "\n[전체 계좌정보]" << endl;
	for (int i = 0; i < current_customer_cnt; i++) {
		cout << "[" << i << "]" << endl;
		customer[i]->accountInfo();
		cout << endl;
	}
}