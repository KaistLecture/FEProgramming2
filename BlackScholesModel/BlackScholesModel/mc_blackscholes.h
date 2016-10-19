#pragma once
#include "analytic_blackscholes.h"
#include "payoff.h" //Payoff 클래스를 이용

double mcprice(double s,
	Payoff& payoff,
	double r,
	double q,
	double t,
	double sigma,
	unsigned int numOfSimulation);