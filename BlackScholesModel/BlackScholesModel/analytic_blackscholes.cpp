
#include <cmath>
#include "analytic_blackscholes.h"
#include "normal.h"

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
