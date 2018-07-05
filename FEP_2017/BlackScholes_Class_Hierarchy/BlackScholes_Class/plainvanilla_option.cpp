#include "plainvanilla_option.h"
#include "normal.h"
#include <cmath>


double PlainVanillaOption::price() {
	double d1 = getd1();
	double d2 = getd2();
	double nd1 = normcdf(type_*d1);
	double nd2 = normcdf(type_*d2);
	double price = type_*(s_*exp(-q_*t_)*nd1 - strike_*exp(-r_*t_)*nd2);
	return price;
}

double PlainVanillaOption::vega() {
	double d1 = getd1();
	double npd1 = normpdf(d1);
	double vega = s_*exp(-q_*t_)*npd1*sqrt(t_);
	return vega;
}

double PlainVanillaOption::impliedVol(double mktPrice, double init, double tol) {
	double x = init;
	double e = 1;
	while (e > tol) {
		setVolatility(x);
		double diff = price() - mktPrice;
		e = abs(diff);
		x = x - diff / vega();
	}
	return x;
}

