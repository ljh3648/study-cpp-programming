#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	Car(int gasolineGauge){
		this->gasolineGauge = gasolineGauge;
	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int electricGauge, int gasolineGauge): Car(gasolineGauge){
		this->electricGauge = electricGauge;
	}
	int GetElecGauge() {
		return electricGauge;
	}
public:
};

class HybridWaterCar : public HybridCar{
private:
	int waterGauge;
public:
	HybridWaterCar(int waterGauge, int electricGauge, int gasolineGauge) : HybridCar(electricGauge, gasolineGauge){
		this->waterGauge = waterGauge;
	}
	void ShowCurrentGauge(){
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
}; 

int main(void){
	HybridWaterCar car1(100,20,30);
	car1.ShowCurrentGauge();
	return 0;
}

