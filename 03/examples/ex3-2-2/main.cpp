#include "Printer.h"


int main(void){
	Printer pnt;
	pnt.SetString((char *)"Hello, World!");
	pnt.ShowString();
	
	return 0;
}