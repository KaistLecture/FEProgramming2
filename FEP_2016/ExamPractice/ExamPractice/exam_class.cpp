#define _USE_MATH_DEFINES
#include "exam_class.h"
#include <cmath>
#include <iostream>

NormalDistribution::NormalDistribution(double mean, double stdev)
	:mean_(mean), stdev_(stdev) {}

double NormalDistribution::pdf(double x) {
	return 1.0 / sqrt(2 * M_PI) / 
		stdev_*exp(-0.5*(x - mean_)*(x - mean_) / (stdev_*stdev_));
}

double NormalDistribution::cdf(double x) {
	double v = (x - mean_) / stdev_;
	return 0.5 * erfc(-v * M_SQRT1_2);
}

Customer::Customer(std::string name, int mileage)
	:name_(name), mileage_(mileage) {}

void Customer::printProfile() {
	std::cout << "Name = " << name_ << std::endl;
	std::cout << "Mile = " << mileage_ << std::endl;
	std::cout << std::string(30, '-') << std::endl;
}

void Customer::addMileage(int m) {
	mileage_ += 0.05 * m;
}

void Customer::useMileage(int m) {
	mileage_ -= m;
}

void SuperCustomer::addMileage(int m) {
	mileage_ += 0.1*m;
}

double YieldTermStructure::forwardRate(double t1, double t2) {
	double df1 = discountFactor(t1);
	double df2 = discountFactor(t2);
	double tau = t2 - t1;
	double fwdRate = 1.0 / tau * (df1 / df2 - 1.0);
	return fwdRate;
}

double YieldTermStructure::interp(double t) {
	if (t <= time_[0])
		return data_[0];
	for (int i = 0; i < data_.size()-1; ++i) {
		if (t > time_[i] && t <= time_[i + 1]) {
			double y = data_[i] + (data_[i + 1] - data_[i]) / (time_[i + 1] - time_[i]) * (t - time_[i]);
			return y;
		}
	}
	return data_.back();
}

double DiscountFactorTermStructure::discountFactor(double t) {
	return interp(t);
}
double DiscountFactorTermStructure::spotRate(double t){
	return (-1.0)*log(discountFactor(t)) / t;
}

double ContinuousRateTermStructure::discountFactor(double t) {
	return exp(-spotRate(t)*t);
}
double ContinuousRateTermStructure::spotRate(double t) {
	return interp(t);
}
