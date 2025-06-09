#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CUSTOMER_CNT 50
#define MAX_NAME_LEN 20

enum CREDITLEVEL {
	A = 7,
	B = 4,
	C = 2,
};

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
	virtual void deposit(int money) {
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
	virtual void accountInfo() const {
		cout << "계좌ID: " << this->id << endl;
		cout << "이  름: " << this->name << endl;
		cout << "잔  액: " << this->balance << endl;
	}
	unsigned int getAccountID() {
		return id;
	}
};

class NormalAccount : public Account {
private:
	int interest_Rate;
public:
	NormalAccount(unsigned int id, char *name, long long int balance, int interest_Rate)
		: Account(id, name, balance), interest_Rate(interest_Rate) {
	}
	virtual void deposit(int money) {
		money = money + (money * (interest_Rate / 100.0));
		Account::deposit(money);
	}
	virtual void accountInfo() const {
		Account::accountInfo();
		cout << "이자율: " << interest_Rate << endl;
	}
};

class HighCreditAccount : public NormalAccount {
private:
	int credit_level;
	int credit_table[3] = { A,B,C };
public:
	HighCreditAccount(unsigned int id, char *name, long long int balance, int interest_Rate, int credit_level)
		:NormalAccount(id, name, balance, interest_Rate), credit_level(credit_level) {
	}
	virtual void deposit(int money) {
		// cout << "HightCreditAccount: deposit called!" << endl;
		NormalAccount::deposit(money);
		Account::deposit(money * (credit_table[credit_level - 1] / 100.0));
	}
	virtual void accountInfo() const {
		NormalAccount::accountInfo();
		cout << "신용등급: " <<  (char)('A' + credit_level -1)  << endl;
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
	int temp_interestRate;
	int credit_level;
	int temp_credit_level;
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
	int getUserMenuSel(int a = 1, int b = 5) {
		int select = 0;

		while (true) {
			cout << "선택: ";
			cin >> select;
			if (a <= select && select <= b) {
				break;
			}
			else {
				cout << "잘못된 선택입니다." << endl;
			}
		}
		return select;
	}
	void newAccountCreate(void) {
		cout << "\n[계좌종류선택]" << endl;
		cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
		int select = getUserMenuSel(1, 2);

		if (select == 1) {
			cout << "[보통예금계좌 개설]" << endl;
			cout << "계좌ID: ";
			cin >> temp_id;
			cout << "이름: ";
			cin >> temp_name;
			cout << "입금액: ";
			cin >> temp_balance;
			cout << "이자율: ";
			cin >> temp_interestRate;
			cout << endl;
			customer[current_customer_cnt++] =
				new NormalAccount(temp_id, temp_name, temp_balance, temp_interestRate);
		}
		else if (select == 2) {
			cout << "[신용신뢰계좌 개설]" << endl;
			cout << "계좌ID: ";
			cin >> temp_id;
			cout << "이름: ";
			cin >> temp_name;
			cout << "입금액: ";
			cin >> temp_balance;
			cout << "이자율: ";
			cin >> temp_interestRate;
			cout << "신용등급(1toA, 2toB, 3toC): ";
			cin >> temp_credit_level;
			cout << endl;
			customer[current_customer_cnt++] =
				new HighCreditAccount(temp_id, temp_name, temp_balance, temp_interestRate, temp_credit_level);
		}
	}

	// customer[current_customer_cnt] = new Account(temp_id, temp_name, temp_balance);
	// current_customer_cnt++;

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