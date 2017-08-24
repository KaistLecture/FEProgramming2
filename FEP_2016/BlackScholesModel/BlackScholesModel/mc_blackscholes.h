#pragma once
#include "analytic_blackscholes.h"
#include "payoff.h" //Payoff Ŭ������ �̿�

double mcprice(double s,
	Payoff& payoff,
	double r,
	double q,
	double t,
	double sigma,
	unsigned int numOfSimulation);