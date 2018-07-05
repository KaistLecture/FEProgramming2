#pragma once

class Payoff
{
public:
	virtual ~Payoff() {}
	virtual double operator()(double s) = 0;
};
