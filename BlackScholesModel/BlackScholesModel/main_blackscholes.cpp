#include <iostream>
#include <fstream>
#include <vector>
#include "analytic_blackscholes.h"
#include "mc_blackscholes.h"
#include "bnt_blackscholes.h"
#include "payoff.h"

typedef std::vector<std::vector<double> > ResultVector;

//ResultVector bsprice_vec(std::vector<double>& s,
//	double k,
//	double r,
//	double q,
//	double t,
//	double sigma,
//	OptionType type,
//	unsigned int numOfSim,
//	unsigned int nsteps);

int main() {
	double s = 100, k = 100, r = 0.02, q = 0.01;
	double t = 91 / 365.0, sigma = 0.2;
	OptionType type = Put;

	double anal_price = bsprice(s, k, r, q, t, sigma, type);
	std::cout << "Analytic Price = " << anal_price << std::endl;

	PlainVanillaPayoff payoff(k, type);
	unsigned int numOfSim = 1000000;
	double mc_price = mcprice(s, payoff, r, q, t, sigma, numOfSim);
	std::cout << "MC Price = " << mc_price << std::endl;
	
	unsigned int nsteps = 300;
	double bnt_price = bntprice(s, payoff, r, q, t, sigma, nsteps);
	std::cout << "BNT Price = " << bnt_price << std::endl;
	/*
	std::ofstream fout("option_prices.csv");
	fout << "S,Analytic,MC,BNT,MC-A,BNT-A" << std::endl;
	std::vector<double> ss;
	for (int i = 0; i <= 40; ++i)
		ss.push_back(80.0 + i);

	std::cout << "\nCalculating Option Prices..." << std::endl;
	ResultVector res = bsprice_vec(ss, k, r, q, t, sigma, type, numOfSim, nsteps);
	
	for (int i = 0; i < res.size(); ++i) {
		fout << ss[i] << ",";
		std::cout << ss[i] << ",";
		for (int j = 0; j < 5; ++j) {
			std::cout.precision(8);
			std::cout << res[i][j] << "\t";
			fout << res[i][j] << ",";
		}
		std::cout << std::endl;
		fout << std::endl;
	}

	fout.close();
	*/
	return 0;
}

/*

ResultVector bsprice_vec(std::vector<double>& s,
	double k,
	double r,
	double q,
	double t,
	double sigma,
	OptionType type,
	unsigned int numOfSim,
	unsigned int nsteps) {	

	ResultVector res;	
	for (int i = 0; i < s.size(); ++i) {
		std::vector<double> x(5);
		x[0] = bsprice(s[i], k, r, q, t, sigma, type);
		x[1] = mcprice(s[i], k, r, q, t, sigma, type, numOfSim);
		x[2] = bntprice(s[i], k, r, q, t, sigma, type, nsteps);
		x[3] = x[1] - x[0];
		x[4] = x[2] - x[0];
		res.push_back(x);
	}
	return res;
}
*/