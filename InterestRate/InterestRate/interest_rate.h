#pragma once

class InterestRate {
public:
	InterestRate(double r) : r_(r) {}
	InterestRate(double r, int freq);
	double discountFactor(double t);
	double forwardRate(double t1, double t2);
private:
	double r_;
};
