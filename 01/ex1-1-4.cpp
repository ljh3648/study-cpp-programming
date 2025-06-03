#include <iostream>

int main(void) {
	int sales_amount;
	while (true) {
		std::cout << "판매 금액을  만원 단위로 입력(-1 to end): ";
		std::cin >> sales_amount;
		if (sales_amount == -1) break;
		std::cout << "이번달 급여: " << 50 + (sales_amount * 0.12) << "만원" << std::endl;
	}

	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}