#include <iostream>
#include <string>
#include "function.h"

#define PI 3.14
#define SQ(x) ((x)*(x))

void f() {
	std::cout << "PI = " << PI << std::endl;
	std::cout << SQ(1 + 2) << std::endl;
	std::cout << char(65) << std::endl;

	int n = 0;
	std::cout << "input = ";
	std::cin >> n;

	if (n == 0)
		throw(std::string("Error 1234: ") + std::string(__FILE__));
	else if (n == 1)
		throw(std::string("Error 4567: ") + std::string(__FILE__));
	else
		std::cout << "Success" << std::endl;
}