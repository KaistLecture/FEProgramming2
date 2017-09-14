#ifndef _Analytic_BlackScholes_H
#define _Analytic_BlackScholes_H

#define MAX(x,y) (((x)>(y))?(x):(y))
enum OptionType { Call = 1, Put = -1 };

double bsprice(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type);

double bsvega(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type);

double bsImpliedVol(double s,
	double k,
	double r,
	double q,
	double t,
	double optionPrice,
	OptionType type,
	double init =0.1,
	double tol = 1e-6);

#endif

