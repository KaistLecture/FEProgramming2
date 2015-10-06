#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

enum BondType {ZeroCoupon, CouponBond, NotDefined};

struct PricingRst {
	double price;
	double npv;
	double duration;
};

double spotRate(int n, int* curve_years, double* spot_rates, double t) {
	if (t > 30)
		throw(std::string("Error: The maturity should be less than 30 years"));

	double spotRate;
	int i;
	for (i = 1; i < n; ++i) {
		if (t <= curve_years[i])
			break;
	}
	spotRate = spot_rates[i - 1] + (spot_rates[i] - spot_rates[i - 1]) 
		/ (curve_years[i] - curve_years[i - 1])
		*(t - curve_years[i - 1]);
	return spotRate / 100.0;
}

PricingRst* bond_pricing(int n, int* curve_years, double* spot_rates, double faceValue, int matYears) {

	double price = 100.0 * std::exp(-spotRate(n, curve_years, spot_rates, matYears) * matYears);
	double duration = matYears;

	PricingRst* rst = new PricingRst;
	rst->price = price;
	rst->npv = price * faceValue / 100.0;
	rst->duration = duration;
	return rst;

}

PricingRst* bond_pricing(int n, int* curve_years, double* spot_rates, double faceValue, int matYears, int freq, double couponRate) {

	double coupon = couponRate / freq;
	double price = 100.0 * std::exp(-spotRate(n, curve_years, spot_rates, matYears) * matYears);
	double duration = matYears * price;

	for (int i = 1; i <= freq*matYears; ++i) {
		double t = (double)i / freq;
		price += coupon * std::exp(-spotRate(n, curve_years, spot_rates, t) * t);
		duration += t * coupon * std::exp(-spotRate(n, curve_years, spot_rates, t) * t);
	}
	duration /= price;

	PricingRst* rst = new PricingRst;
	rst->price = price;
	rst->npv = price * faceValue / 100.0;
	rst->duration = duration;
	return rst;
}

int main() {

	try {
		int num = 10;
		int curve_years[10] = { 0, 1, 2, 3, 5, 7, 10, 15, 20, 30 };
		double spot_rates[10] = { 1.5, 1.5, 1.6, 1.8, 2, 2.2, 2.5, 2.7, 2.8, 2.9 };	

		std::ifstream in("bond_input.csv");
		if (!in) throw(std::string("file open error"));
		std::string str;
		std::string token;
		int count = 0;

		BondType type;
		double faceValue, couponRate;
		int mat, freq;
		std::vector<double> prices, npvs, durations;

		std::cout << "No\tType\tPrice\t\tNPV\t\tDuration\n";
		std::cout << "---------------------------------------------------------\n";

		while (in.good()) {
			std::cout<<++count<<".\t";
			std::getline(in, str);
			std::istringstream iss(str);
			std::vector<std::string> inputValues;
			while (std::getline(iss, token, ',')) {
				inputValues.push_back(token);
			}
			type = (inputValues[0] == "Z") ? ZeroCoupon : ((inputValues[0] == "C") ? CouponBond : NotDefined);
			faceValue = std::stod(inputValues[1]);
			mat = std::stoi(inputValues[2]);

			PricingRst* rst;
			switch (type) {
			case ZeroCoupon :
				rst = bond_pricing(num, curve_years, spot_rates, faceValue, mat);
				break;
			case CouponBond :
				freq = std::stoi(inputValues[3]);
				couponRate = std::stod(inputValues[4]);
				rst = bond_pricing(num, curve_years, spot_rates, faceValue, mat, freq, couponRate);
				break;
			default:
				throw(std::string("not defined bond type"));
			}
			
			prices.push_back(rst->price);
			npvs.push_back(rst->npv);
			durations.push_back(rst->duration);
			
			std::cout << ((type == ZeroCoupon) ? "ZC" : "C") << "\t";
			std::cout << rst->price << "\t\t";
			std::cout << rst->npv << "\t\t";
			std::cout << rst->duration << std::endl;
			
			delete rst;
		}

		double aggValue=0, aggDuration=0;
		for (unsigned int i = 0; i < npvs.size(); ++i) {
			aggValue += npvs[i];
			aggDuration += durations[i] * npvs[i];
		}
		aggDuration /= aggValue;

		std::cout << "---------------------------------------------------------\n";
		std::cout << "aggregate\t\t\t" << aggValue << "\t\t" << aggDuration << std::endl;
		std::cin.get();
		return 0;
	}

	catch (std::string e) {
		std::cout << e << std::endl;
		std::cin.get();
		return -1;
	}

}