
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : customer(MAX_CUSTOMER_CNT) {
	current_customer_cnt = 0;
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < current_customer_cnt; ++i) {
		delete customer[i];
	}
}

void AccountHandler::showMenu(void) const {
	cout << "--------Menu--------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료 " << endl;
}

int AccountHandler::getUserMenuSel(int a, int b) {
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

void AccountHandler::newAccountCreate(void) {
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

void AccountHandler::deposit() {
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

void AccountHandler::Withdrawal() {
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

void AccountHandler::showAllAccountInfo() {
	cout << "\n[전체 계좌정보]" << endl;
	for (int i = 0; i < current_customer_cnt; i++) {
		cout << "[" << i << "]" << endl;
		customer[i]->accountInfo();
		cout << endl;
	}
}