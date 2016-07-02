
#include <iostream>
int main() {
	int donuts = 6;
	double cups = 4.5;
	int* p = &donuts;
	
	std::cout << donuts << std::endl;
	std::cout << &donuts << std::endl;
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
	std::cout << &p << std::endl;
	(*p)++;
	std::cout << donuts << std::endl;


	std::cout << "----------------" << std::endl;

	double wage[3] = { 10, 20, 30 };
	int stack[5] = { 3,5,7,9,1 };
	std::cout << *wage << "\t" <<
		*(wage+1) << std::endl;
	std::cout << *stack << "\t" << 
		*(stack+1) << std::endl;

	bool b = (5>4);
	bool c = false;



	return 0;
}
