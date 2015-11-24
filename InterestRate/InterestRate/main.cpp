#include <cmath>
#include <iostream>
#include <vector>

class Array {
public:
	Array(std::vector<double> data) :
		data_(data) {}
	double min();
	double max();
	double sum();
	double at(int i) {
		return data_[i];
	}
	int size() {
		return data_.size();
	}
private:
	std::vector<double> data_;
};

Array add(Array& a1, Array& a2);
double innerProduct(Array& a1, Array& a2);





class InterestRate {
public:
	InterestRate(double r) : r_(r) {}
	InterestRate(double r, int freq) {
		r_ = freq * std::log(1 + r / freq);
	}
	double discountFactor(double t) {
		double df = std::exp(-r_*t);
		return df;
	}
	double forwardRate(double t1, double t2) {
		double f = 1.0 / (t2 - t1) * 
			(discountFactor(t1)
			/ discountFactor(t2) - 1);
		return f;
	}
private:
	double r_;
};


int main() {

	InterestRate p(0.05);
	InterestRate q = InterestRate(0.04, 4);
	InterestRate* r = new InterestRate(0.07, 12);

	double df1 = p.discountFactor(3);
	double df2 = q.discountFactor(3);
	double f1 = p.forwardRate(2, 2.5);
	double f2 = q.forwardRate(3, 3.25);

	double df3 = r->discountFactor(5);
	double f3 = r->forwardRate(3, 4);

	std::cout << df1 << std::endl;
	std::cout << df2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << df3 << std::endl;
	std::cout << f3 << std::endl;
	delete r;

	return 0;
}