
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include "BlackScholesFormulas.h"
#include "option.h"

using namespace std;


int main()
{
	CallOption c(100, 0.25);
	double price = c.calc(100, 0.05, 0.01, 0.2);
	std::cout << "Price = " << price << std::endl;

	price = c.calc(101, 0.05, 0.01, 0.2);
	std::cout << "Price = " << price << std::endl;


	PutOption p(100, 0.25);
	price = p.calc(100, 0.05, 0.01, 0.2);
	std::cout << "Price = " << price << std::endl;

	price = p.calc(101, 0.05, 0.01, 0.2);
	std::cout << "Price = " << price << std::endl;


	//try {
	//	ofstream out("bs_price.csv");0.2

	//	double Expiry = 0.25;
	//	double Strike = 100;
	//	double Spot = 100;
	//	double r = 0.02;
	//	double d = 0.01;
	//	double vol = 0.25;

	//	//Spot 80 to 120
	//	for (int i = 0; i <= 40; ++i) {
	//		Spot = 80.0 + i;
	//		double callPrice = BlackScholes(Call, Spot, Strike, r, d, vol, Expiry);
	//		double putPrice = BlackScholes(Put, Spot, Strike, r, d, vol, Expiry);
	//		double digCall = BlackScholes(DigCall, Spot, Strike, r, d, vol, Expiry);
	//		double digPut = BlackScholes(DigPut, Spot, Strike, r, d, vol, Expiry);
	//		cout << Spot << "\t";
	//		cout << callPrice << "\t";
	//		cout << putPrice << "\t";
	//		cout << digCall << "\t";
	//		cout << digPut << "\n";

	//		out << Spot << ",";
	//		out << callPrice << ",";
	//		out << putPrice << ",";
	//		out << digCall << ",";
	//		out << digPut << "\n";
	//	}
	//	//cout << "call option price = " << callPrice << endl;
	//	//cout << "put option price = " << putPrice << endl;
	//	out.close();
	//	cin.get();
	//}
	//catch (std::string& e) {
	//	std::cout << e << std::endl;
	//}
	return 0;
}

/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/

