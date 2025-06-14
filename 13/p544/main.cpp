#include <iostream>
#include "PointTemplate.h"
#include "PointTemplate.cpp"
using namespace std;

int main(void){
    Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(3.14, 23.1);
	pos2.ShowPosition();
	
	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
    
    return 0;
}