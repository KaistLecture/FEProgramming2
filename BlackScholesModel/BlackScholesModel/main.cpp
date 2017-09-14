
#include <iostream>
#include "normal.h"
#include "analytic_blackscholes.h"
#include "mc_blackscholes.h"
#include "bnt_blackscholes.h"
#include <ctime>

#define PI 3.141592

int main() {
	clock_t starttime = clock();

	double s = 100, k = 100, r = 0.02, q = 0.01, t = 0.25;
	double sigma = 0.21;
	OptionType type = Call;
	for (int i = 0; i < 10; i++) {
		sigma = 0.1 + i / 50.0;
		double price = bsprice(s, k, r, q, t, sigma, type);
		double vega = bsvega(s, k, r, q, t, sigma, type);
	
		std::cout << "price = " << price << "   ";
		//std::cout << "vega = " << vega << std::endl;
		//std::cout << "Imp Vol = " <<
		//	bsImpliedVol(s, k, r, q, t, price, type)
		//	<< std::endl;

		double mc = mcprice(s, k, r, q, t, sigma, type, 10000000);
		std::cout << "mc price = " << mc << std::endl;

		double bnt = bntprice(s, k, r, q, t, sigma, type, 200);
		std::cout << "bnt price = " << bnt << std::endl;

		std::cout << "--------------" << std::endl;
	}
	//for (int i = 0; i <= 200; ++i) {
	//	double x = -2.0 + i*0.02;
	//	double pdf = normpdf(x, 0, 1);
	//	double cdf = normcdf(x, 0, 1);
	//	/*
	//	std::cout << x << "\t";
	//	std::cout << pdf << "\t";
	//	std::cout << cdf << std::endl;
	//	*/
	//	double y = PI * 10;
	//	printf("%0.2f : %0.6f  | %0.6f\n", x, pdf, cdf);
	//}
	std::cout << "time = " << (clock() - starttime) 
		/ (double)CLOCKS_PER_SEC << " sec" << std::endl;
	return 0;
}