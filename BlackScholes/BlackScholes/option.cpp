
#include "option.h"
#include "Normals.h"
#include <cmath>

double CallOption::calc(double spot, double r, double d, double vol) {
	double standardDeviation = vol*sqrt(t_);
	double moneyness = log(spot / strike_);
	double d1 = (moneyness + (r - d)*t_ + 0.5* standardDeviation*standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	double price = spot*exp(-d*t_) * CumulativeNormal(d1)
		- strike_*exp(-r*t_)*CumulativeNormal(d2);
	return price;
}

double PutOption::calc(double spot, double r, double d, double vol) {
	double standardDeviation = vol*sqrt(t_);
	double moneyness = log(spot / strike_);
	double d1 = (moneyness + (r - d)*t_ + 0.5* standardDeviation*standardDeviation) / standardDeviation;
	double d2 = d1 - standardDeviation;
	double price = -spot*exp(-d*t_) * CumulativeNormal(-d1)
		+ strike_*exp(-r*t_)*CumulativeNormal(-d2);
	return price;
}