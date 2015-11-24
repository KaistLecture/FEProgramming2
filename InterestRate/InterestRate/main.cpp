#include <cmath>
#include <iostream>
#include "interest_rate.h"


int main() {

	InterestRate p(0.05);
	InterestRate q = InterestRate(0.04, 4);
	InterestRate* r = new InterestRate(0.07, 12);

	double df1 = p.discountFactor(3);
	double df2 = q.discountFactor(3);
	double f1 = p.forwardRate(2, 2.5);
	double f2 = q.forwardRate(3, 3.25);

	double df3 = r->discountFactor(5);
	double f3 = r->forwardRate(3, 4);

	std::cout << df1 << std::endl;
	std::cout << df2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << df3 << std::endl;
	std::cout << f3 << std::endl;
	delete r;

	return 0;
}