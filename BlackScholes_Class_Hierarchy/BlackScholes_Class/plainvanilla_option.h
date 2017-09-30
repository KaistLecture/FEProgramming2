#pragma once
#include "option.h"

class PlainVanillaOption : public Option {
public:	
	PlainVanillaOption(Date expiration, double strike, OptionType type) : 
		Option(expiration, strike, type) {}
	double price();
	double vega();
	double impliedVol(double mktPrice, double init = 0.1, double tol = 1e-6);

private:
	void setVolatility(double sigma) { 
		sigma_ = sigma; 
	}
};