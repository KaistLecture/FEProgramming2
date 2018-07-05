
#include <iostream>
#include <ctime>
#include "plainvanilla_option.h"

int main() {
	clock_t starttime = clock();
	Date evalDate(2017, 9, 1);
	Date mat(2017, 10, 31);
	double spot = 100, stk = 100, rf = 0.01, div = 0.01, vol = 0.2;
	OptionType type = Call;
	PlainVanillaOption inst(mat, stk, type);
	GBMProcess process(spot, rf, div, vol);
	inst.setProcess(process);
	
	std::cout << "price = " << inst.price(evalDate) << std::endl;
	std::cout << "vega = " << inst.vega(evalDate) << std::endl;
	double mktPrice = 4.1;
	std::cout << "implied vol = " << inst.impliedVol(evalDate, mktPrice) << std::endl;

	std::cout << "time = " << (clock() - starttime)
		/ (double)CLOCKS_PER_SEC << " sec" << std::endl;
	return 0;
}

