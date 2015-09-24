#include <cmath>
#include "process.h"

double BlackScholesProcess::standardDeviation(double t) {
	return *volatility_ * sqrt(t);
}
