#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "main.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int credit_level;
	int credit_table[3] = { A,B,C };
public:
	HighCreditAccount(unsigned int id, String name, long long int balance, int interest_Rate, int credit_level)
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

#endif