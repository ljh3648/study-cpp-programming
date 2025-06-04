#include <iostream>
#include <cstring>
#include "car.h"
using namespace std;

class Car {
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(char *ID, int fule);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(char *ID, int fuel){
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed=0;
}

void Car::ShowCarState() {
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() {
	if (fuelGauge <= 0) {
		return;
	}
	else {
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void) {
	Car run99;
	run99.InitMembers((char *)"run99", 100);
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
}