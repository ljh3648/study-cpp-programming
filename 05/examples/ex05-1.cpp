#include <iostream>
#include <cstring>
using namespace std;


namespace COMP_POS {
	enum {
		CLERK,	 // 사원
		SENIOR,  // 주임
		ASSIST,  // 대리
		MANAGER  // 과장
	};
};

class NameCard {
private:
	char *name;
	char *company_name;
	char *phone_number;
	int rank;

public:
	NameCard(const char *n,const char *cn,const char *pn, int r) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		company_name = new char[strlen(cn) + 1];
		strcpy(company_name, cn);
		phone_number = new char[strlen(pn) + 1];
		strcpy(phone_number, pn);
		rank = r;
	}
	NameCard(NameCard &copy)
		: rank(copy.rank) {
		name = new char[strlen(copy.name) + 1];
		company_name = new char[strlen(copy.company_name) + 1];
		phone_number = new char[strlen(copy.phone_number) + 1];
		strcpy(name, copy.name);
		strcpy(company_name, copy.company_name);
		strcpy(phone_number, copy.phone_number);
	}


	void ShowNameCardInfo() {
		cout << "이름: " << name << endl;
		cout << "회사: " << company_name << endl;
		cout << "전화번호: " << phone_number << endl;
		cout << "직급: ";
		ShowRankInfo(rank);
		cout << endl << endl;
	}

	void ShowRankInfo(int r) {
		switch (r) {
		case COMP_POS::CLERK:
			cout << "사원";
			break;
		case COMP_POS::SENIOR:
			cout << "주임";
			break;
		case COMP_POS::ASSIST:
			cout << "대리";
			break;
		case COMP_POS::MANAGER:
			cout << "과장";
			break;
		default:
			break;
		}
	}

	~NameCard() {
		delete[]name;
		delete[]company_name;
		delete[]phone_number;
	}
};

int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}