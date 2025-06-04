#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>

class Printer{
private:
	char str[50];
public:
	void SetString(char *);
	void ShowString();
};

#endif