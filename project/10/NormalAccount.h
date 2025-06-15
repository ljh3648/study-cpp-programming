#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "main.h"
#include "Account.h"

class NormalAccount : public Account {
private:
	int interest_Rate;
public:
	NormalAccount(unsigned int id, String name, long long int balance, int interest_Rate)
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

#endif