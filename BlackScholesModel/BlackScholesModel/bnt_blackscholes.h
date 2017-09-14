#pragma once
#include "analytic_blackscholes.h"

double bntprice(double s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type,
	unsigned int nsteps);
