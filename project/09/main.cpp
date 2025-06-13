#include "main.h"
#include "AccountHandler.h"

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