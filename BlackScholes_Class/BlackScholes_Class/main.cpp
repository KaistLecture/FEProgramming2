
#include "process.h"
#include "plain_vanilla.h"
#include <vector>

#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void print(int n, Instrument* i) {
	std::cout << n << ":\t";
	std::cout << i->name() << "\t";
	std::cout << i->NPV() << std::endl;
}

int main()
{
	
	double* spot = new double(100);
	double* r = new double(0.02);
	double* d = new double(0.01);
	double* vol = new double(0.25);

	std::vector<Instrument*> inst;
	inst.push_back(new PlainVanillaCall(100, 0.25));
	inst.push_back(new PlainVanillaPut(100, 0.1));
	inst.push_back(new PlainVanillaCall(100, 0.4));

	Process* p = new BlackScholesProcess(spot, r, d, vol);

	std::cout << "Spot Price = " << *spot << std::endl;
	for (unsigned int i = 0; i < inst.size(); ++i) {
		inst[i]->setProcess(p);
		inst[i]->calc();
		print(i+1, inst[i]);		
	}

	*spot = 110;
	std::cout << "\nSpot Price = " << *spot << std::endl;
	for (unsigned int i = 0; i < inst.size(); ++i) {
		inst[i]->calc();
		print(i + 1, inst[i]);
	}

	*spot = 90;
	std::cout << "\nSpot Price = " << *spot << std::endl;
	for (unsigned int i = 0; i < inst.size(); ++i) {
		inst[i]->calc();
		print(i + 1, inst[i]);
	}

	for (unsigned int i = 0; i < inst.size(); ++i) {
		delete inst[i];
	}
	delete p;
	delete spot, r, d, vol;

	return 0;
}

