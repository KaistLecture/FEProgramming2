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


class CCRate {
public:
	CCRate(double r) : r_(r) {}
	virtual double discountFactor(double t);
	double forwardRate(double t1, double t2);
protected:
	double r_;
};

class DCRate : public CCRate {
public:
	DCRate(double r, int freq) : CCRate(r), freq_(freq) {}
	double discountFactor(double t);
	//double forwardRate(double t1, double t2);
private:
	int freq_;
};