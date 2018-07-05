#pragma once
#include "option.h"
#include "payoff.h"
#include <iostream>

class BinaryPayoff : public Payoff
{
public:
	BinaryPayoff(double strike, OptionType type) :
		strike_(strike), type_(type) {}
	double operator()(double s) { return (type_*(s - strike_) > 0) ? 1.0 : 0.0; }
private:
	double strike_;
	OptionType type_;
};

class BinaryOption : public Option
{
public:
	BinaryOption(Date expiration, double strike, OptionType type) :
		Option(expiration, strike, type) {
		payoff_ = new BinaryPayoff(strike, type);
	}
	~BinaryOption() { 
		std::cout << "binary destruction" << std::endl; 
	}
	double price();
};