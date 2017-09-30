#pragma once
#include "option.h"

enum BarrierType { UpIn, UpOut, DownIn, DownOut };

class BarrierOption : public Option
{
public:
	BarrierOption(Date expiration, double strike, OptionType type,
		double barrier, BarrierType btype) :
		Option(expiration, strike, type), barrier_(barrier), btype_(btype) 
	{}
	~BarrierOption();

protected:
	double barrier_;
	BarrierType btype_;
};

