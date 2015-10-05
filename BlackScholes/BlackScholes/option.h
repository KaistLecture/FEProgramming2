#pragma once

class CallOption {
public:
	CallOption(double strike, double t)
		: strike_(strike), t_(t) {}
	double calc(double spot, double r, double d, double vol);
private:
	double strike_;
	double t_;
};

class PutOption {
public:
	PutOption(double strike, double t)
		: strike_(strike), t_(t) {}
	double calc(double spot, double r, double d, double vol);
private:
	double strike_;
	double t_;
};