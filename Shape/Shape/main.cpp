
#include <iostream>
#include "shape.h"

int main() {
	Square* s = new Square(10);
	Square* r = new Rect(10, 5);
	double a = s->area();
	double b = r->area();
	std::cout << "Square = " << a << std::endl;
	std::cout << "Rect = " << b << std::endl;
	delete s;
	delete r;
	return 0;
}