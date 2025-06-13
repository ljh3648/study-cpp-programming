#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "StringClass.h"

class Account {
private:
	unsigned int id;
	// char *name;
	String name;
	long long int balance;
public:
	Account(unsigned int id, String name, long long int balance);
	// Account(Account &copy);
	virtual ~Account();
	virtual void deposit(int money);
	int withDrawal(int money);
	virtual void accountInfo() const;
	unsigned int getAccountID();
};

#endif