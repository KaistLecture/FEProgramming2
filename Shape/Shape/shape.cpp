
#include "shape.h"

Square::Square(double a) : a_(a) {}
double Square::area() {
	return a_*a_;
}

Rect::Rect(double a, double b) : Square(a) {
	b_ = b;
}
double Rect::area() {
	return a_*b_;
}



