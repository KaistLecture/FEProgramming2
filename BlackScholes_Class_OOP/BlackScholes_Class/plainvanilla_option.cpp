#include "plainvanilla_option.h"
#include "normal.h"
#include <cmath>

double PlainVanillaOption::bsprice(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type) {

	double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
	double d2 = d1 - sigma*sqrt(t);
	double nd1 = normcdf(type*d1);
	double nd2 = normcdf(type*d2);
	double price = type*(s*exp(-q*t)*nd1 - k*exp(-r*t)*nd2);
	return price;
}

double PlainVanillaOption::bsvega(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type) {
	double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
	double npd1 = normpdf(d1);
	double vega = s*exp(-q*t)*npd1*sqrt(t);
	return vega;
}


double PlainVanillaOption::price(Date evalDate) {
	double t = daysBetween(evalDate, expiration_) / 365.0;
	double s = p_.getSpot();
	double r = p_.getRf();
	double q = p_.getDiv();
	double sigma = p_.getVol();
	return bsprice(s, strike_, r, q, t, sigma, type_);
}

double PlainVanillaOption::vega(Date evalDate) {
	double t = daysBetween(evalDate, expiration_) / 365.0;
	double s = p_.getSpot();
	double r = p_.getRf();
	double q = p_.getDiv();
	double sigma = p_.getVol();
	return bsvega(s, strike_, r, q, t, sigma, type_);
}

double PlainVanillaOption::impliedVol(Date evalDate, double mktPrice, double init, double tol) {
	double t = daysBetween(evalDate, expiration_) / 365.0;
	double s = p_.getSpot();
	double r = p_.getRf();
	double q = p_.getDiv();
	double sigma = p_.getVol();

	double x = init;
	double e = 1;
	while (e > tol) {
		double diff = bsprice(s, strike_, r, q, t, x, type_) - mktPrice;
		e = abs(diff);
		x = x - diff / bsvega(s, strike_, r, q, t, x, type_);
	}
	return x;
}