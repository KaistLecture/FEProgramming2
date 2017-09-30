#pragma once

#include "date.h"
#include "GBMProcess.h"

enum OptionType { Call = 1, Put = -1 };

class PlainVanillaOption {
public:	
	PlainVanillaOption(Date expiration, double strike, OptionType type) : 
		expiration_(expiration), strike_(strike), type_(type) {}
	void setProcess(GBMProcess p) { p_ = p; }	

	double price(Date evalDate);
	double vega(Date evalDate);
	double impliedVol(Date evalDate, double mktPrice, double init = 0.1, double tol = 1e-6);

private:
	double bsprice(double s, double k, double r, double q, double t, double sigma, OptionType type);
	double bsvega(double s,	double k, double r, double q, double t,	double sigma, OptionType type);
	Date expiration_;
	double strike_;
	OptionType type_;
	GBMProcess p_;
};