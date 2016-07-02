#pragma once
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
