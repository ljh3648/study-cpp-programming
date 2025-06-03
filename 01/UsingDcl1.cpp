#include <iostream>

namespace Hybird {
	void HybFunc(void) {
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}
}

int main(void) {
	using Hybird::HybFunc;
	HybFunc();
	return 0;
}