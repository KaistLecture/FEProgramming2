#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "normal.h"

double normpdf(double x, double mu, double sigma) {
	return 1 / sqrt(2 * M_PI) / sigma*exp(-0.5*(x - mu)*(x - mu) / (sigma*sigma));
	//pow(x-mu,2)
}

double normcdf(double x, double mu, double sigma) {
	double v = (x - mu) / sigma;
	return 0.5 * erfc(-v * M_SQRT1_2);
}

class YieldTermStructure {
public:
	virtual double discountFactor(double t) = 0;
	virtual double spotRate(double t) = 0;
	double forwardRate(double t1, double t2);
protected:
	double interp(double x);
	std::vector<double> time, data;
};

class DiscountFactorTermStructure : public YieldTermStructure {
public:
	virtual double discountFactor(double t);
	virtual double spotRate(double t);
};

class ContinuousRateTermStructure : public YieldTermStructure {
public:
	virtual double discountFactor(double t);
	virtual double spotRate(double t);
};
