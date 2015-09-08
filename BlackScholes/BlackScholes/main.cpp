
#include <cmath>
#include <iostream>
#include "BlackScholesFormulas.h"

using namespace std;

int main()
{

	double Expiry = 0.25;
	double Strike = 100;
	double Spot = 100;
	double r = 0.02;
	double d = 0.01;
	double vol = 0.25;

    double callPrice = BlackScholesCall(Spot,Strike,r,d,vol,Expiry);
	double putPrice = BlackScholesPut(Spot, Strike, r, d, vol, Expiry);
	cout << "call option price = " << callPrice << endl;
	cout << "put option price = " << putPrice << endl;
	
	cin.get();

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

