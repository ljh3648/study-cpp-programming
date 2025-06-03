#include <iostream>

int main(void){
	int arr[5], total = 0;
	for(int i = 0; i < 5; i++){
		std::cout << "1번째 정수 입력: ";
		std::cin >> arr[i];
		total += arr[i];
	}

	std::cout << "합계:" << total << std::endl;
	return 0;
}