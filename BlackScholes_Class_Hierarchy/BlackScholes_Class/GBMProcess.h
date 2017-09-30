#pragma once
class GBMProcess
{
public:
	GBMProcess() {}
	GBMProcess(double spot, double rf, double div, double vol) :
		spot_(spot), rf_(rf), div_(div), vol_(vol) {}
	double getSpot() { return spot_; }
	double getRf() { return rf_; }
	double getDiv() { return div_; }
	double getVol() { return vol_; }
	~GBMProcess() {};
private:
	double spot_, rf_, div_, vol_;
};
