
#include  <iostream>
#include <vector>
#include "shape.h"

void print(std::vector<Shape*>& s) {
	for (unsigned int i = 0; i < s.size(); ++i) {
		std::cout <<
			s[i]->area() << "\t" <<
			s[i]->length() << "\t" <<
			s[i]->getColor() << std::endl;
	}
}

int main() {
	

	Shape* b = new Circle(1, "black");
	Shape* c = new Rect(2, 3, "yellow");
	Shape* p = new Circle(4, "green");
	Shape* q = new Rect(2, 5, "pink");

	std::vector<Shape*> s;
	s.push_back(b);
	s.push_back(c);
	s.push_back(p);
	s.push_back(q);

	print(s);

	delete p;
	delete b;
	delete c;
	delete q;

	return 0;

}