#include <cmath>
#include "analytic_blackscholes.h"
#include "normal.h"
#include <iostream>

double bsprice(double s,
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

double bsvega(double s,
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

double bsImpliedVol(double s,
	double k,
	double r,
	double q,
	double t,
	double optionPrice,
	OptionType type,
	double init,
	double tol) {

	double x = init;
	double e = 1;
	while (e > tol) {
		double diff = bsprice(s, k, r, q, t, x, type) - optionPrice;
		e = abs(diff);
		x = x - diff / bsvega(s, k, r, q, t, x, type);
		//std::cout << x << std::endl;
	}
	return x;
}


