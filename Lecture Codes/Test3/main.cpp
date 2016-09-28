//Lecture 3
#include <iostream>
#include "normal.h"

#define XYZ 10 //MACRO º¯¼ö
#define F(x) (x)*(x)

#ifndef WXYZ
double foo() {
	return 10;
}
#else
double foo() {
	return 20;
}
#endif
typedef double Yield;

int main() {
	std::cout << foo() << std::endl;

	//&& ||
	if (1 == 2 && 10 > 5)
		std::cout << "True" << std::endl;
	else
		std::cout << F(1+3) << std::endl;

	Yield p = normcdf(0);
	std::cout << p << std::endl;

	//header file
	
	//macro

	//array

	//vector

	//reference
	
	//function overloading

	//random normal dist.

	return 0;
}