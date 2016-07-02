#include <iostream>
#include "array.h"

double Array::min() {
	unsigned int n = data_.size();
	double min = data_[0];
	for (unsigned int i = 1; i < n; ++i) {
		if (data_[i] < min)
			min = data_[i];
	}
	return min;
}
double Array::max() {
	unsigned int n = data_.size();
	double max = data_[0];
	for (unsigned int i = 1; i < n; ++i) {
		if (data_[i] > max)
			max = data_[i];
	}
	return max;
}
double Array::sum() {
	unsigned int n = data_.size();
	double sum = 0;
	for (unsigned int i = 1; i < n; ++i)
		sum += data_[i];	
	return sum;
}
Array add(Array& a1, Array& a2) {
	std::vector<double> temp;
	if (a1.size() != a2.size())
		std::cout << "The sizes should be equal." << std::endl;
	else {		
		for (unsigned int i = 0; i < a1.size(); ++i)
			temp.push_back(a1.at(i) + a2.at(i));
	}
	return Array(temp);
}
double innerProduct(Array& a1, Array& a2) {
	double temp = 0;
	if (a1.size() != a2.size())
		std::cout << "The sizes should be equal." << std::endl;
	else {
		for (unsigned int i = 0; i < a1.size(); ++i)
			temp += a1.at(i) * a2.at(i);
	}
	return temp;
}