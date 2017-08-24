#pragma once
#include <string>
#include <vector>

class NormalDistribution {
public:
	NormalDistribution(double mean, double stdev);
	double pdf(double x);
	double cdf(double x);
private:
	double mean_, stdev_;
};

class Customer {
public:
	Customer(std::string name, int mileage = 0);
	void printProfile();
	void addMileage(int m);
	void useMileage(int m);
protected:
	std::string name_;
	int mileage_;
};

class SuperCustomer : public Customer {
public:
	SuperCustomer(std::string name, int mileage = 0) :
		Customer(name, mileage) {}
	void addMileage(int m); //function override
};

class YieldTermStructure {
public:
	YieldTermStructure(std::vector<double> time, std::vector<double> data) :
		time_(time), data_(data) {}
	virtual double discountFactor(double t) = 0;
	virtual double spotRate(double t) = 0;
	double forwardRate(double t1, double t2);
protected:
	double interp(double x);
	std::vector<double> time_, data_;
};

class DiscountFactorTermStructure : public YieldTermStructure {
public:
	DiscountFactorTermStructure(std::vector<double> time, std::vector<double> data) :
		YieldTermStructure(time, data) {}
	virtual double discountFactor(double t);
	virtual double spotRate(double t);
};

class ContinuousRateTermStructure : public YieldTermStructure {
public:
	ContinuousRateTermStructure(std::vector<double> time, std::vector<double> data) :
		YieldTermStructure(time, data) {}
	virtual double discountFactor(double t);
	virtual double spotRate(double t);
};