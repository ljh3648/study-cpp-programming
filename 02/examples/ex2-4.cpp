#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	char str1[20] = "Hello";
	char str2[20] = " world!\n";
	char str3[20];

	int size = strlen(str1);
	strcpy(str3, str1);

	cout << str3 << endl;

	if(strcmp(str1, str3) == 0){
		cout << "str1, str3 is same" << endl;
	}

	strcat(str3, str2);

	cout << str3 << endl;
	return 0;
}