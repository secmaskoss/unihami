#include <iostream>
#include <string>
#include <Windows.h>
extern "C" int __stdcall doSkip();
int main(){
	std::string i;
	std::cout << doSkip() << std::endl;
	std::cin >> i;
}