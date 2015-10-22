#pragma once
#include <string>
#include "process.h"

class Instrument {
public:
	Instrument(std::string name) : name_(name), npv_(0.0) {}
	virtual void calc() = 0;
	void setProcess(Process* p) {
		p_ = p;
	}
	double NPV() {
		return npv_;
	}
	std::string name() {
		return name_;
	}
protected:
	Process* p_;
	std::string name_;
	double npv_;
};

class Option : public Instrument {
public:
	Option(std::string name, double strike, double expiry) 
		: Instrument(name), strike_(strike), expiry_(expiry), d1_(0.0), d2_(0.0) {}
	void init();
protected:
	double strike_;
	double expiry_;
	double d1_, d2_;
};

