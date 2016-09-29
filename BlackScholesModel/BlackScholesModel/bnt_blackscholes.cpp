#include "bnt_blackscholes.h"
#include <vector>

double bntprice(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type,
	unsigned int nsteps) {
	
	double dt = t / nsteps;
	double u = exp(sigma*sqrt(dt));
	double d = 1 / u;
	double p = (exp((r-q)*dt) - d) / (u - d);
	double df = exp(-r*dt);
	
	std::vector<double> v(nsteps + 1, 0.0);
	for (int j = 0; j <= nsteps; ++j) {
		double st = s*pow(u, nsteps - j)*pow(d, j);
		v[j] = MAX(type*(st - k), 0);
	}

	for (int i = nsteps-1; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			v[j] = df*(v[j] * p + v[j + 1] * (1 - p));
		}
	}
	return v[0];
}