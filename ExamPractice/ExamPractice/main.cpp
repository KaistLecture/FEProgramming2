#include <iostream>
#include <iomanip>
#include <string>
#include "exam_practice.h"
#include "exam_class.h"

void printCurveData(YieldTermStructure& y, double t) {
	std::cout << "time = " << std::setw(3) << t << "\t";
	std::cout << "DF =   " << std::setw(10) << y.discountFactor(t) << "\t";
	std::cout << "Spot = " << std::setw(10) << y.spotRate(t) << "\t";
	std::cout << "Fwd =  " << std::setw(10) << y.forwardRate(t, t + 0.25) << std::endl;
}

int main() {
	//p1
	std::cout << "---Practice 1---" << std::endl;
	unsigned int n = generateNormal();
	std::cout << "numbers = " << n << std::endl;

	//p2
	std::cout << "\n---Practice 2---" << std::endl;
	std::vector<double> s = sumBetween2Nums();
	std::cout << "sum=" << s[0] << "\t" << "sum of sq. = " << s[1] << std::endl;

	//p3
	std::cout << "\n---Practice 3---" << std::endl;
	int m = 10;
	std::vector<int> f = fibonacci(m);
	for (int i = 0; i < f.size(); ++i)
		std::cout << f[i] << "\t";
	std::cout << std::endl;

	//p4
	std::cout << "\n---Practice 4---" << std::endl;
	for (int i = 0; i < 4; ++i) {
		double income = 5000 * (i + 1);
		double tax = calcTax(income);
		std::cout << "Tax of " << income << " = " << tax << std::endl;
	}

	//p5
	std::cout << "\n---Practice 5---" << std::endl;
	std::vector<double> inputData = { 1,2,3,4,5,4,3,2,1 };
	std::vector<double> stats = calcStats(inputData);
	std::vector<std::string> labels = { "min","max","mean","variance","stdev" };
	for (int i = 0; i < stats.size(); ++i) {
		std::cout << labels[i] << " = " << stats[i] << std::endl;
	}

	//p6
	std::cout << "\n---Practice 6---" << std::endl;
	NormalDistribution dist(10, 10);
	for (int i = 0; i <= 20; ++i) {
		std::cout << "f(" << i << ")=" << dist.pdf(i) << "\t";
		std::cout << "f(x<" << i << ")=" << dist.cdf(i) << std::endl;
	}

	//p7
	std::cout << "\n---Practice 7---" << std::endl;
	Customer c1("Jack");
	SuperCustomer c2("Jane", 100);
	c1.addMileage(10000);
	c2.addMileage(10000);
	c1.useMileage(100);
	c2.useMileage(100);
	c1.printProfile();
	c2.printProfile();

	//p8
	std::cout << "\n---Practice 8---" << std::endl;
	std::vector<double> t = { 1,2,3,4,5 };
	std::vector<double> r = { 0.02,0.03,0.04,0.05,0.06 };
	std::vector<double> df = { 0.95,0.9,0.85,0.8,0.75 };
	ContinuousRateTermStructure y1(t, r);
	DiscountFactorTermStructure y2(t, df);
	for (int i = 1; i <= 10; ++i) {
		printCurveData(y1, i);
		printCurveData(y2, i);
		std::cout << std::string(30, '-') << std::endl;
	}

	return 0;
}