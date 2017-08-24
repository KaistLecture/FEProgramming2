#include "payoff.h"

PlainVanillaPayoff::PlainVanillaPayoff(double strike, OptionType type)
	: strike_(strike), type_(type) {}

double PlainVanillaPayoff::getPayoff(double s) {
	return (type_*(s - strike_)) > 0 ? type_*(s - strike_) : 0;
}

DigitalPayoff::DigitalPayoff(double strike, OptionType type)
	: strike_(strike), type_(type) {}

double DigitalPayoff::getPayoff(double s) {
	return (type_*(s - strike_) > 0) ? 1 : 0;
}