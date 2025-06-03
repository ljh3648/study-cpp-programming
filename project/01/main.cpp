#include <iostream>

#define MAX_CUSTOMER_CNT 50
#define MAX_NAME_LEN 20

typedef struct account {
	bool active_flag;
	unsigned int id;
	char name[MAX_NAME_LEN];
	long long int balance;
	struct account *ptr;
} Account;

namespace Bank {
	using namespace std;

	int select;

	void showMenu();
	int getUserMenuSel();
	int newAccountCreate(Account *);
	int deposit(Account *, int);
	int Withdrawal(Account *, int);
	void showAllAccountInfo(Account *, int);
	// void process(int select);
}

int main(void) {
	Account customer[MAX_CUSTOMER_CNT] = { 0 };
	int current_customer_cnt = 0;
	Bank::select = 0;

	while (true) {
		Bank::showMenu();
		Bank::select = Bank::getUserMenuSel();
		// Bank::process(Bank::select);
		switch (Bank::select) {
		case 1:
			Bank::newAccountCreate(&customer[current_customer_cnt]);
			current_customer_cnt++;// Bank::process(Bank::select);
			break;
		case 2:
			Bank::deposit(&customer[0], current_customer_cnt);
			break;
		case 3:
			Bank::Withdrawal(&customer[0], current_customer_cnt);
			break;
		case 4:
			Bank::showAllAccountInfo(&customer[0], current_customer_cnt);
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

int Bank::newAccountCreate(Account *customer) {
	cout << "\n[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> (*customer).id;

	cout << "이름: ";
	cin >> (*customer).name;

	cout << "입금액: ";
	cin >> (*customer).balance;

	cout << endl;

	(*customer).active_flag = true;

	return 0;
}

int Bank::deposit(Account *customer, int current_customer_cnt) {
	Account temp;
	bool flag = false;
	int index = 0;
	cout << "\n[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> temp.id;

	for (int i = 0; i < current_customer_cnt; i++) {
		if ((*(customer + i)).id == temp.id) {
			index = i;
			flag = true;
		};
	}

	if (flag == false) {
		cout << "잘못된 계좌ID 입니다. " << endl;
		return 1;
	}

	cout << "입금액: ";
	cin >> temp.balance;

	(*(customer + index)).balance += temp.balance;

	cout << "입금완료 " << endl;
	return 0;
}

int Bank::Withdrawal(Account *customer, int current_customer_cnt) {
	Account temp;
	bool flag = false;
	int index = 0;
	cout << "\n[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> temp.id;

	for (int i = 0; i < current_customer_cnt; i++) {
		if ((*(customer + i)).id == temp.id) {
			index = i;
			flag = true;
		};
	}

	if (flag == false) {
		cout << "잘못된 계좌ID 입니다. " << endl;
		return 1;
	}

	cout << "출금액: ";
	cin >> temp.balance;

	if ((*(customer + index)).balance - temp.balance < 0) {
		cout << "출금 가능한 금액이 부족합니다." << endl;
		return 1;
	}

	(*(customer + index)).balance -= temp.balance;

	cout << "출금완료 " << endl;
	return 0;
}

void Bank::showAllAccountInfo(Account *customer, int current_customer_cnt) {
	cout << "\n[전체 계좌정보]" << endl;
	for (int i = 0; i < current_customer_cnt; i++) {
		if ((*customer).active_flag == false) break;
		cout << "[" << i << "]" << endl;
		cout << "계좌ID: " << (*(customer + i)).id << endl;
		cout << "이  름: " << (*(customer + i)).name << endl;
		cout << "잔  액: " << (*(customer + i)).balance << endl;
		cout << endl;
	}
}

// void Bank::process(int select) {
// 	// cout << "선택된 번호는: " << select << endl;
// }