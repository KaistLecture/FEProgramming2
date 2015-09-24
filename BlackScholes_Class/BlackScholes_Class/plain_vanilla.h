#pragma once

#include "instruments.h"

class PlainVanillaCall : public Option {
public:
	PlainVanillaCall(double strike, double expiry, std::string name = "Vanilla Call")
		: Option(name, strike, expiry) {}
	virtual void calc();
};

class PlainVanillaPut : public Option {
public:
	PlainVanillaPut(double strike, double expiry, std::string name = "Vanilla Put")
		: Option(name, strike, expiry) {}
	virtual void calc();
};