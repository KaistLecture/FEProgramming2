#include <iostream>
#include <string>
#include "function.h"
#include "function2.h"

int main() {

	//try-catch-throw
	try {
		f();
	}
	catch(std::string e) {
		std::cout << e << std::endl;
	}

	std::cout << "-----------------" << std::endl;
	try {
		f2();
	}
	catch (std::string e) {
		std::cout << e << std::endl;
	}

	//Pointer
	std::cout << "-----------------" << std::endl;
	int a = 10;
	int* p = &a;
	std::cout << p << " " << *p << std::endl;
	
	int b[4] = { 1,3,5,7 };
	for (int i = 0; i < 4; i++) {
		std::cout << b[i] << " " << b+i << " " << *(b+i) << std::endl;
	}

	int* c = new int;
	*c = 5;
	std::cout << c << " " << *c << std::endl;
	delete c;

	int* d = new int[5];
	for (int i = 0; i < 5; i++) {
		d[i] = i*i;
		std::cout << d[i] << " " << d + i << " " << *(d + i) << std::endl;
	}
	delete[] d;

	std::cin.get();
}