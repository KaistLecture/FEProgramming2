#include <iostream>
#include <vector>
#include "array.h"

int main() {

	double v1[5] = { 3, 6, 8, 1, 3 };
	double v2[5] = { 1, 6, -2, 5, -7 };
	std::vector<double> d1(v1, v1 + 5);
	std::vector<double> d2(v2, v2 + 5);

	Array a(d1);
	Array b(d2);

	std::cout << "Max = " << a.max() << std::endl;
	std::cout << "Min = " << a.min() << std::endl;
	std::cout << "Sum = " << a.sum() << std::endl;	

	Array c = add(a, b);
	double value = innerProduct(a, b);
	std::cout << "a+b = ( ";
	for (unsigned int i = 0; i < c.size(); ++i)
		std::cout << c.at(i) << "  ";
	std::cout << ")" << std::endl;
	std::cout << "Inner product = " << value << std::endl;

	return 0;
}

