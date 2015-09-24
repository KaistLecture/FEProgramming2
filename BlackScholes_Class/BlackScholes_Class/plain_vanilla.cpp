
#include "plain_vanilla.h"
#include "Normals.h"

void PlainVanillaCall::calc() {
	init();
	npv_ = p_->spotPrice()*exp(-p_->dividendRate()*expiry_) * CumulativeNormal(d1_) 
		- strike_*exp(-p_->riskfreeRate()*expiry_)*CumulativeNormal(d2_);
}


void PlainVanillaPut::calc() {
	init();
	npv_ = strike_*exp(-p_->riskfreeRate()*expiry_)*(1 - CumulativeNormal(d2_))
		- p_->spotPrice()*exp(-p_->dividendRate()*expiry_) * (1 - CumulativeNormal(d1_));
}