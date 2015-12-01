#include <cmath>
#include "interest_rate.h"

InterestRate::InterestRate(double r, int freq) {
	r_ = freq * std::log(1 + r / freq);
}

double InterestRate::discountFactor(double t) {
	double df = std::exp(-r_*t);
	return df;
}
double InterestRate::forwardRate(double t1, double t2) {
	double f = 1.0 / (t2 - t1) *
		(discountFactor(t1)
			/ discountFactor(t2) - 1);
	return f;
}

double CCRate::discountFactor(double t) {
	double df = std::exp(-r_*t);
	return df;
}
double CCRate::forwardRate(double t1, double t2) {
	double f = 1.0 / (t2 - t1) *
		(discountFactor(t1)
			/ discountFactor(t2) - 1);
	return f;
}
double DCRate::discountFactor(double t) {
	double df = 1.0 / std::pow(1.0 + r_ / freq_, freq_*t);
	return df;
}
double DCRate::forwardRate(double t1, double t2) {
	double f = 1.0 / (t2 - t1) *
		(discountFactor(t1)
			/ discountFactor(t2) - 1);
	return f;
}