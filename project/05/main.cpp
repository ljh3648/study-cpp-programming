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
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->balance = balance;
	}
	Account(Account &copy)
		:id(copy.id), balance(copy.balance) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	~Account() {
		delete[]name;
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
	void accountInfo() const {
		cout << "계좌ID: " << this->id << endl;
		cout << "이  름: " << this->name << endl;
		cout << "잔  액: " << this->balance << endl;
		cout << endl;
	}
	unsigned int getAccountID() {
		return id;
	}
};

class AccountHandler {
private:
	int current_customer_cnt;
	Account *customer[MAX_CUSTOMER_CNT];
	unsigned int temp_id;
	char temp_name[100];
	long long int temp_balance;
	long long int temp_money;
public:
	AccountHandler()
		: current_customer_cnt(0) {
	}
	~AccountHandler() {
		for (int i = 0; i < current_customer_cnt; ++i) {
			delete customer[i];
		}
	}
	void showMenu(void) const {
		cout << "--------Menu--------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료 " << endl;
	}
	int getUserMenuSel(void) {
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
	void newAccountCreate(void) {
		cout << "\n[계좌개설]" << endl;
		cout << "계좌ID: ";
		cin >> temp_id;

		cout << "이름: ";
		cin >> temp_name;

		cout << "입금액: ";
		cin >> temp_balance;

		cout << endl;

		customer[current_customer_cnt] = new Account(temp_id, temp_name, temp_balance);
		current_customer_cnt++;
	}
	void deposit() {
		cout << "\n[입   금]" << endl;
		cout << "계좌ID: ";
		cin >> temp_id;

		for (int i = 0; i < current_customer_cnt; i++) {
			if (temp_id == customer[i]->getAccountID()) {
				cout << "입금액: ";
				cin >> temp_money;
				customer[i]->deposit(temp_money);
				cout << "입금완료 " << endl;
				return;
			}
		}

		cout << "잘못된 계좌ID 입니다. " << endl;
		return;
	}
	void Withdrawal() {
		cout << "\n[출   금]" << endl;
		cout << "계좌ID: ";
		cin >> temp_id;

		for (int i = 0; i < current_customer_cnt; i++) {
			if (temp_id == customer[i]->getAccountID()) {
				cout << "출금액: ";
				cin >> temp_money;
				customer[i]->withDrawal(temp_money);
				cout << "출금완료 " << endl;
				return;
			}
		}

		cout << "잘못된 계좌ID 입니다. " << endl;
		return;
	}
	void showAllAccountInfo() {
		cout << "\n[전체 계좌정보]" << endl;
		for (int i = 0; i < current_customer_cnt; i++) {
			cout << "[" << i << "]" << endl;
			customer[i]->accountInfo();
			cout << endl;
		}
	}
};

int main(void) {
	AccountHandler tossBank;
	while (true) {
		tossBank.showMenu();
		int select = tossBank.getUserMenuSel();
		switch (select) {
		case 1:
			tossBank.newAccountCreate();
			break;
		case 2:
			tossBank.deposit();
			break;
		case 3:
			tossBank.Withdrawal();
			break;
		case 4:
			tossBank.showAllAccountInfo();
			break;
		case 5:
			return 0;
		default: return EOF;
		}
	}
	return 0;
}