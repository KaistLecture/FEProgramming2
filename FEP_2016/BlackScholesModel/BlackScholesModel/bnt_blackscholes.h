#pragma once
#include "analytic_blackscholes.h"
#include "payoff.h"

double bntprice(double s,
	Payoff& payoff,
	double r,
	double q,
	double t,
	double sigma,
	unsigned int nsteps);