#include <iostream>
#include <ctime>
#include <string>
#include "plainvanilla_option.h"
#include "binary_option.h"
#include "BarrierOption.h"
#include <vector>

int main() {
	Date evalDate(2017, 9, 1);
	Date mat(2017, 10, 31);
	double spot = 100, stk = 100, rf = 0.01, div = 0.01, vol = 0.2;
	OptionType type = Call;
	PlainVanillaOption inst(mat, stk, type);
	BinaryOption inst2(mat, stk, type);

	GBMProcess process(spot, rf, div, vol);
	inst.setProcess(process);
	inst.setEvalDate(evalDate);

	inst2.setProcess(process);
	inst2.setEvalDate(evalDate);

	std::cout << "price = " << inst.price() << std::endl;
	std::cout << "vega = " << inst.vega() << std::endl;
	std::cout << "imp vol = " << inst.impliedVol(4.0) << std::endl;
	std::cout << std::string(30, '-') << std::endl;
	std::cout << "price2 = " << inst2.price() << std::endl;
	std::cout << "vega = " << inst2.vega() << std::endl;
	std::cout << "imp vol = " << inst2.impliedVol(4.0) << std::endl;

	double b = 90;
	BarrierType btype = DownOut;
	BarrierOption inst3(mat, stk, type, b, btype);
	std::cout << std::string(30, '-') << std::endl;
	std::cout << "price3 = " << inst3.price() << std::endl;
	std::cout << "vega = " << inst3.vega() << std::endl;
	std::cout << "imp vol = " << inst3.impliedVol(4.0) << std::endl;

	std::vector<BinaryOption*> t;
	BinaryOption* p = &inst2;
	for (int i = 1; i < 30; ++i) {
		t.push_back(p);
	}

	for (int i = 0; i < 29; ++i) {
		std::cout << t[i]->price() << std::endl;
	}


	return 0;
}
