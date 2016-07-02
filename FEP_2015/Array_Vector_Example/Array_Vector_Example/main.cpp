#include <iostream>
#include <vector>

std::vector<double*> lowerTriangle(int n) {
	std::vector<double*> ret;
	for (unsigned int i = 0; i < n; ++i) {
		double* temp = new double[i + 1];
		for (unsigned int j = 0; j <= i; ++j)
			temp[j] = i*std::exp(j);
		ret.push_back(temp);
	}
	return ret;
}

int main() {

	int n = 10;
	std::vector<double*> triangle = lowerTriangle(n);
	for (unsigned int i = 0; i < triangle.size(); ++i) {
		for (unsigned int j = 0; j <= i; ++j)
			std::cout << triangle[i][j] << "\t\t";
		std::cout << std::endl;
	}
	
	for (unsigned int i = 0; i < triangle.size(); ++i)
		delete[] triangle[i];

	return 0;
}