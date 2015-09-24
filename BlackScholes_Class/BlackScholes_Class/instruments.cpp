#include "instruments.h"

void Option::init() {

	double standardDeviation = p_->standardDeviation(expiry_);
	double moneyness = log(p_->spotPrice() / strike_);
	d1_ = (moneyness + (p_->riskfreeRate() - p_->dividendRate())*expiry_ + 0.5* standardDeviation*standardDeviation) / standardDeviation;
	d2_ = d1_ - standardDeviation;

}