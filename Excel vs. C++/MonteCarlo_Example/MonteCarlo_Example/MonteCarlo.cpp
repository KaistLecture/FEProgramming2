#include "MonteCarlo.h"
#include <math.h>
#include <boost/random.hpp>
#include <boost/timer.hpp>

void MonteCarlo(
	double *h_CallResult,
	double *h_CallConfidence,
	double *S,
	double *X,
	double *T
	)
{
	typedef boost::mt19937                     ENG;    // Mersenne Twister
	typedef boost::normal_distribution<double> DIST;    // Normal Distribution
	typedef boost::variate_generator<ENG, DIST> GEN;    // Variate generator

	ENG  eng;
	DIST dist(0, 1);
	GEN  gen(eng, dist);


	for (int opt = 0; opt < OPT_N; opt++)
	{
		double VBySqrtT = VOLATILITY * sqrt(T[opt]);
		double MuByT = (RISKFREE - 0.5 * VOLATILITY * VOLATILITY) * T[opt];
		double Sval = S[opt];
		double Xval = X[opt];
		double val = 0.0, val2 = 0.0;

		for (int pos = 0; pos < RAND_N; pos++)
		{
			double temp = Sval *exp(MuByT + VBySqrtT *  gen()) - Xval;
			double callValue = (temp > 0.) ? temp : 0.;
			val += callValue;
			val2 += callValue * callValue;
		}

		double exprt = exp(-RISKFREE *T[opt]);
		h_CallResult[opt] = exprt * val / (double)RAND_N;
		double stdDev = sqrt(((double)RAND_N * val2 - val * val) / ((double)RAND_N * (double)(RAND_N - 1)));
		h_CallConfidence[opt] = (double)(exprt * stdDev / sqrtf((double)RAND_N));
	}
}


int main() {
	boost::timer timer;
	double h_CallResult[OPT_N];
	double h_CallConfidence[OPT_N];
	double S[OPT_N], X[OPT_N], T[OPT_N];

	for (int i = 0; i < OPT_N; ++i) {
		S[i] = 100.;
		X[i] = 100.;
		T[i] = 0.25;
	}

	MonteCarlo(h_CallResult, h_CallConfidence, S, X, T);

	for (int i = 0; i < OPT_N; ++i) {
		std::cout.precision(4);
		std::cout.width(10);
		std::cout << S[i] << ": ";
		std::cout.width(10);
		std::cout << h_CallResult[i];
		std::cout.width(15);
		std::cout << h_CallConfidence[i] << std::endl;
	}

	std::cout << "\ntime = " << timer.elapsed() << " sec" << std::endl;
	return 0;
}