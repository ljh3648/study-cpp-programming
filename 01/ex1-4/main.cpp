#include "main.h"

// vsCode를 통해서 빌드 하려면 직접 해당 폴더를 새로운 창으로 열어서 빌드를 해야함.
// 그리고 takes.json 파일을 만들어서 모든 *.cpp 파일을 컴파일 하도록 명령어 추가.
// "${fileDirname}/*.cpp",

// 터미널 창을 이용해서 빌드 하려면 해당 폴더를 들어가서 다음 명령어 입력
// $g++-13 -std=c++17 namesp2.cpp main.cpp -o main
// 현재 컴파일러는 g++-13을 사용하고 있음

// makefile 이용하기.

int main(void){
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}