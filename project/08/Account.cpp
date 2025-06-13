#include "main.h"
#include "Account.h"

Account::Account(unsigned int id, char *name, long long int balance) {
	this->id = id;
	this->balance = balance;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(Account &copy) :id(copy.id), balance(copy.balance) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

Account::~Account() {
	delete[]name;
}

void Account::deposit(int money) {
	this->balance += money;
}

int Account::withDrawal(int money) {
	if (this->balance < money) {
		cout << "잔액 부족" << endl;
		return 1;
	}
	this->balance -= money;
	return 0;
}

void Account::accountInfo() const {
	cout << "계좌ID: " << this->id << endl;
	cout << "이  름: " << this->name << endl;
	cout << "잔  액: " << this->balance << endl;
}

unsigned int Account::getAccountID() {
	return id;
}