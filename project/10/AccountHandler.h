#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "main.h"
#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler {
private:
	int current_customer_cnt;
	BoundCheckArray<Account*> customer;
	unsigned int temp_id;
	// char temp_name[100];
	String temp_name;
	long long int temp_balance;
	long long int temp_money;
	int temp_interestRate;
	int credit_level;
	int temp_credit_level;
public:
	AccountHandler();
	~AccountHandler();
	void showMenu(void) const;
	int getUserMenuSel(int a = 1, int b = 5);
	void newAccountCreate(void);
	void deposit();
	void Withdrawal();
	void showAllAccountInfo();
};

#endif