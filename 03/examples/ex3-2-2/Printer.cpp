#include "Printer.h"
#include <cstring>
using namespace std;

void Printer::SetString(char *temp){
	strcpy(str, temp);
}
void Printer::ShowString(){
	cout << str << endl;
}