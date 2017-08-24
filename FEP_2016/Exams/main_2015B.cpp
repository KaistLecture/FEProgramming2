
#include <iostream>
#include "goodluck.h"

int main() {

	//PROBLEM 1.
	std::vector<double*> bt = binomialTree(64, 2, 5);
	std::cout << "(1)" << std::endl;
	for (unsigned int i = 0; i < bt.size(); ++i) {
		for (unsigned int j = 0; j <= i; ++j) {
			std::cout << bt[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	for (unsigned int i = 0; i < bt.size(); ++i)
		delete[] bt[i];

	//PROBLEM 2.
	double d[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<double> data(d, d + 10);
	Series s(data);
	std::cout << "\n(2)" << std::endl;
	std::cout << "mean = " << s.mean() << std::endl;
	std::cout << "stdev = " << s.stdev() << std::endl;

	//PROBLEM 3.
	int n = 10;
	Dist* b = new Binomial(n, 0.3);
	Dist* p = new Poisson(3);
	std::cout.setf(std::ios::fixed);
	std::cout << "\n(3)" << std::endl;
	std::cout << "\t" << b->getName() << "\t\t\t" << p->getName() << std::endl;
	std::cout << std::string(70,'-') << std::endl;
	for (int i = 0; i <= n; ++i) {
		std::cout << i << "\t";		
		std::cout << b->pdf(i) << "\t";
		std::cout << b->cdf(i) << "\t"; 
		std::cout << p->pdf(i) << "\t";
		std::cout << p->cdf(i) << std::endl;
	}
	std::cout << std::endl;

	delete b;
	delete p;

	return 0;
}
