#include "exam_practice.h"
#include <iostream>
#include <random>
#include <cmath>

unsigned int generateNormal() {
	std::mt19937_64 gen;
	std::normal_distribution<double> engine(0, 1);
	unsigned int n = 1;
	double x = engine(gen);
	while (x <= 2) {
		n++;
		x = engine(gen);
	}
	return n;
}

std::vector<double> sumBetween2Nums() {
	int a, b;
	std::cout << "number 1 = ";
	std::cin >> a;
	std::cout << "number 2 = ";
	std::cin >> b;
	int s = (a > b) ? b : a;
	int e = (a > b) ? a : b;
	std::vector<double> res(2,0);
	for (int i = s; i <= e; ++i) {
		res[0] += i;
		res[1] += i*i;
	}
	return res;
}

std::vector<int> fibonacci(int n) {
	std::vector<int> res;
	for (int i = 0; i < n; ++i) {
		if (i < 2)
			res.push_back(1);
		else
			res.push_back(res[i - 2] + res[i - 1]);
	}
	return res;
}

double calcTax(double x) {
	double tax = 0;
	if (x <= 1200)
		tax = 0.06*x;
	else if (x <= 4600)
		tax = 0.15*x - 108;
	else if (x <= 8800)
		tax = 0.24*x - 522;
	else if (x <= 15000)
		tax = 0.35*x - 1490;
	else
		tax = 0.38*x - 1940;
	return tax;
}

std::vector<double> calcStats(std::vector<double> data) {
	std::vector<double> res(5);
	int n = data.size();
	double min, max, mean, var, stdev;
	min = max = data[0];
	mean = 0;
	var = 0;
	for (int i = 1; i < n; ++i) {
		if (data[i] < min)
			min = data[i];
		if (data[i] > max)
			max = data[i];
		mean += data[i];
		var += data[i] * data[i];
	}
	mean /= n;
	var = var/n  - mean*mean;
	stdev = sqrt(var);
	res[0] = min;
	res[1] = max;
	res[2] = mean;
	res[3] = var;
	res[4] = stdev;
	return res;
}