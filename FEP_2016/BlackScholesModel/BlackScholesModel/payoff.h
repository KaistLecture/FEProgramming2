#pragma once
#include "analytic_blackscholes.h"

class Payoff { //base class , abstract
public:
	virtual double getPayoff(double s) = 0; //pure virtual func.
};

class PlainVanillaPayoff : public Payoff {
public:
	PlainVanillaPayoff(double strike, OptionType type);
	virtual double getPayoff(double s);
protected:
	double strike_;
	OptionType type_;
};

class DigitalPayoff : public Payoff {
public:
	DigitalPayoff(double strike, OptionType type);
	virtual double getPayoff(double s);
protected:
	double strike_;
	OptionType type_;
};