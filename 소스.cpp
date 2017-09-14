#include <iostream>
#include <string>
#include <random>
#include <vector>

#define PI 3.141592
#define SQ(x)  ((x)*(x))
#define MAX(a,b) (((a)>(b))?(a):(b))
int main() {

	std::vector<int> v(5, 100);
	v.push_back(10);
	v.push_back(12);
	v.push_back(15);
	for (int i = 0; i < v.size(); ++i)
		std::cout << i << " : " << v[i] << std::endl;


	double sq = SQ(3+2); // ((3+2)*(3+2))
	double m = MAX(3, 5);
	std::cout << m << std::endl;
	
	/*
	char a[10] = "abcd";
	char* b = "1234";
	strcpy_s(a, b);
	std::cout << a << "\t" << b << std::endl;

	std::string s = "string";
	std::cout << s << std::endl;

	std::mt19937 gen;
	std::normal_distribution<double> dist(0, 1);
	for (int i = 0; i < 100; ++i) {
		double r = dist(gen);
		printf("random number = %0.6f\n", r);
	}
	for (int i = 0; i < 10; ++i)
		std::cout << rand() << std::endl;
	std::cout << RAND_MAX << std::endl;


	*/
	return 0;
}

/*
#include <iostream>
#include <random>
#include <string>
int main() {
	const int nrolls = 10000; // number of experiments
	const int nstars = 100; // maximum number of stars to distribute
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(5.0, 2.0);
	int p[10] = {};
	for (int i = 0; i<nrolls; ++i) {
		double number = distribution(generator);
		if ((number >= 0.0) && (number<10.0)) ++p[int(number)];
	}
	std::cout << "normal_distribution (5.0,2.0):" << std::endl;
	for (int i = 0; i<10; ++i) {
		std::cout << i << "-" << (i + 1) << ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}
	return 0;
}
*/