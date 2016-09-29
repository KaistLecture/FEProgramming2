#define _USE_MATH_DEFINES
#include <cmath>
#include "normal.h"

double normpdf(double x, double mu, double sigma) {
	return 1 / sqrt(2 * M_PI) / sigma*exp(-0.5*(x - mu)*(x - mu) / (sigma*sigma));
	//pow(x-mu,2)
}

double normcdf(double x, double mu, double sigma) {
	double v = (x - mu) / sigma;
	return 0.5 * erfc(-v * M_SQRT1_2);
}