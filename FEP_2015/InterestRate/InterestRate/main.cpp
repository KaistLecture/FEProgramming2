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

	std::cout << "5% Continuous DF = " << df1 << std::endl;
	std::cout << "4% Quarterly DF = " << df2 << std::endl;
	std::cout << "5% Continuous Fwd = " << f1 << std::endl;
	std::cout << "4% Quarterly Fwd = " << f2 << std::endl;
	std::cout << "7% Monthly DF = " << df3 << std::endl;
	std::cout << "7% Monthly Fwd = " << f3 << std::endl;
	delete r;

	//NEW Classes
	CCRate p1(0.05);
	DCRate q1 = DCRate(0.04, 4);
	DCRate* r1 = new DCRate(0.07, 12);
	CCRate* r2 = new DCRate(0.07, 12);

	df1 = p1.discountFactor(3);
	df2 = q1.discountFactor(3);
	f1 = p1.forwardRate(2, 2.5);
	f2 = q1.forwardRate(3, 3.25);

	df3 = r1->discountFactor(5);
	f3 = r1->forwardRate(3, 4);

	std::cout << std::endl;
	std::cout << "5% Continuous DF = " << df1 << std::endl;
	std::cout << "4% Quarterly DF = " << df2 << std::endl;
	std::cout << "5% Continuous Fwd = " << f1 << std::endl;
	std::cout << "4% Quarterly Fwd = " << f2 << std::endl;
	std::cout << "7% Monthly DF = " << df3 << std::endl;
	std::cout << "7% Monthly Fwd = " << f3 << std::endl;

	std::cout << "7% Monthly DF = " << r2->discountFactor(5) << std::endl;
	std::cout << "7% Monthly Fwd = " << r2->forwardRate(3,4) << std::endl;
	delete r1;
	delete r2;


	return 0;
}