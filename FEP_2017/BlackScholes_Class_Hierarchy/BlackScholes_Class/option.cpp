#include "option.h"
#include <cmath>

void Option::setEvalDate(Date d) {
	evalDate_ = d;
	t_ = daysBetween(evalDate_, expiration_) / 365.0; 
}

void Option::setProcess(GBMProcess p) {
	p_ = p;
	s_ = p_.getSpot();
	r_ = p_.getRf();
	q_ = p_.getDiv();
	sigma_ = p_.getVol();
}

double Option::getd1() {
	return (log(s_ / strike_) + (r_ - q_ + 0.5*sigma_*sigma_)*t_) / (sigma_*sqrt(t_));
}
double Option::getd2() {
	return getd1() - sigma_*sqrt(t_);
}