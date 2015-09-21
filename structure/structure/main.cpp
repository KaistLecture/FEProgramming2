
#include <iostream>
#include "function.h"

int main() {

	double d = 1.5;
//	double d = 5;
	{
		double d = 5;
		d++;
		std::cout << d << std::endl;
	}
	d++;
	std::cout << d << std::endl;

	int i;
	for (i = 0; i < 10; ++i) {
		int p = 10;
	}
	std::cout << i << std::endl;




	std::cout << "Hello" << std::endl;
	Example temp;
	temp.a = 3;
	temp.b = 10;
	int* c = addNum(&temp);
	std::cout << *c << std::endl;
	delete c;

	return 0;
}

