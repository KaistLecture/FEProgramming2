//1. Solving Linear Equation (20pts)
//2. OLS (30pts)
//3. Formulas (50pts)

#include <iostream>
#include "header.h"

#define _Prob1
#define _Prob2
#define _Prob3

void printResult(int rst, double* value) {
	switch (rst) {
	case 0:
		std::cout << "x=" << value[0]
			<< "\ty=" << value[1] << std::endl;
		break;
	case 1:
		std::cout << "There is no solution" << std::endl;
		break;
	case 2:
		std::cout << "There are infinitely many solutions" << std::endl;
		break;
	}
}

int main() {
#ifdef _Prob1
	double coeff1[3] = { 2,4,6 };
	double coeff2[3] = { 3,2,1 };
	double value[2];
	
	int rst = solveEquation(coeff1, coeff2, value);
	printResult(rst, value);

	coeff1[0] = 6;
	rst = solveEquation(coeff1, coeff2, value);
	printResult(rst, value);

	coeff1[2] = 2;
	rst = solveEquation(coeff1, coeff2, value);
	printResult(rst, value);

	std::cout << std::endl;
#endif
#ifdef _Prob2
	// P2
	double xdata[6] = { 1,2,3,4,5,6 };
	double ydata[6] = { 10,7,8,4,2,3 };

	std::valarray<double> x(xdata, 5);
	std::valarray<double> y(ydata, 5);
	OLS ols1(x, y);
	double* est1 = ols1.params();
	std::cout << "alpha=" << est1[0]
		<< "\tbeta=" << est1[1] << std::endl;
	delete[] est1;

	x = std::valarray<double>(xdata, 6);
	y = std::valarray<double>(ydata, 6);
	OLS ols2(x, y);
	double* est2 = ols2.params();
	std::cout << "alpha=" << est2[0]
		<< "\tbeta=" << est2[1] << std::endl;
	delete[] est2;

	std::cout << std::endl;
#endif
#ifdef _Prob3
	// P3
	double t = 3;
	std::vector<double> c1(2, 1);
	std::vector<double> c2(5, 1);
	std::vector<Formula*> f;
	f.push_back(new Polynomial(c1));
	f.push_back(new Polynomial(c2, "2nd Poly"));
	f.push_back(new Exp(0.5, "ExpForm"));
	f.push_back(new Ln(4));

	for (unsigned int i = 0; i < f.size(); ++i)
		std::cout << f[i]->getName() << ":\t" 
		<< f[i]->value(t) << "\t" 
		<< f[i]->firstDerivative(t) << "\t" 
		<< f[i]->secondDerivative(t) << std::endl;

	std::cout << std::endl;
	
	for (unsigned int i = 0; i < f.size(); ++i)
		delete f[i];

#endif
	return 0;
}