#include "mc_blackscholes.h"
#include <random>

double mcprice(double s, double k, double r, double q, double t, double sigma, OptionType type, unsigned int numOfSimulation) {

	double sumOfPayoff = 0;
	double df = exp(-r*t);
	std::mt19937_64 gen;
	std::normal_distribution<double> engine(0.0, 1.0);
	gen.seed(std::random_device{}());
	double es = s*exp((r - q - 0.5*sigma*sigma)*t);
	double diffution = sigma*sqrt(t);
	for (unsigned int i = 0; i < numOfSimulation; ++i) {
		double e = engine(gen);
		for (int j = 0; j < 2; ++j) {
			double st = es * exp(diffution*(1 - j * 2)*e);
			double p = MAX(type*(st - k), 0);
			sumOfPayoff += df * p;
		}
	}
	return sumOfPayoff / numOfSimulation / 2.0;
}
