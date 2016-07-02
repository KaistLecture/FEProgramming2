
#include <iostream>

int main() {
	int s, e;	
	bool isValid = true;
	do {
		if (!isValid)
			std::cout << "ERROR" << std::endl;
		std::cout << "Start = ";
		std::cin >> s;
		std::cout << "End = ";
		std::cin >> e;
		isValid = (s <= e);
	} while (!isValid);

	int* a1 = new int[e + 1];
	int* a2 = new int[e + 1];

	int sum = 0;
	for (int i = 0; i <= e; ++i) {
		a2[0] = 1;
		a2[i] = 1;
		for (int j = 1; j < i; ++j)
			a2[j] = a1[j-1] + a1[j];

		if (i >= s) {
			for (int j = 0; j <= i; ++j) {
				std::cout << a2[j] << "\t";
				sum += a2[j];
			}			
			std::cout << std::endl;
		}

		for (int j = 0; j <= i; ++j) {
			a1[j] = a2[j];
		}
	}
	std::cout << "Sum = " << sum << std::endl;

	delete[] a1;
	delete[] a2;

	return 0;
}