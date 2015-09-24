#pragma once
#include <cmath>

class Process {
public:
	virtual double standardDeviation(double t) = 0;
	virtual double spotPrice() = 0;
	virtual double riskfreeRate() = 0;
	virtual double dividendRate() = 0;
};

class BlackScholesProcess : public Process {
public:	
	virtual double spotPrice() { return *spotPrice_; }
	virtual double riskfreeRate() { return *riskfreeRate_; }
	virtual double dividendRate() { return *dividendRate_; }
	virtual double standardDeviation(double t);
	BlackScholesProcess(double* spotPrice, double* riskfreeRate, double* dividendRate, double* volatility)
		: Process(), spotPrice_(spotPrice), riskfreeRate_(riskfreeRate), dividendRate_(dividendRate), volatility_(volatility) {}
private:
	double* spotPrice_;
	double* riskfreeRate_;
	double* dividendRate_;
	double* volatility_;
};
