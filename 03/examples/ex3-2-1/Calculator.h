#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>

class Calculator {
private:
	int cnt;

public:
	void Init();
	double Add(double A, double B);
	double Min(double A, double B);
	double Mul(double A, double B);
	double Div(double A, double B);
};

#endif