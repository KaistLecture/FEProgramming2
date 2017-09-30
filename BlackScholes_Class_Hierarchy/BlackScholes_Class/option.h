#pragma once

#include "date.h"
#include "GBMProcess.h"
enum OptionType { Call = 1, Put = -1 };

class Option {
public:
	Option(Date expiration, double strike, OptionType type) :
		expiration_(expiration), strike_(strike), type_(type) {}
	void setProcess(GBMProcess p);
	void setEvalDate(Date d);
	double price() { return 0; }
	double vega() { return 1; }
	double impliedVol(double m) { return 10; }

protected:
	double getd1();
	double getd2();

	Date evalDate_;
	Date expiration_;
	double strike_;
	OptionType type_;
	GBMProcess p_;
	double s_, r_, q_, t_, sigma_;
};
