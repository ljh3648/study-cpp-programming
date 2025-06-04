#include "Calculator.h"

void Calculator::Init() {
	cnt = 0;
}

double Calculator::Add(double A, double B) {
	cnt++;
	return A + B;
}
double Calculator::Min(double A, double B) {
	cnt++;
	return A - B;
}
double Calculator::Mul(double A, double B) {
	cnt++;
	return A * B;
}
double Calculator::Div(double A, double B) 
{
	cnt++;
	return A / B;
}