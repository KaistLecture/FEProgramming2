#include "shape.h"


void Shape::setColor(std::string color) {
	color_ = color;
}
std::string Shape::getColor() {
	return color_;
}

double Circle::area() { 
	return 3.14*r_*r_;
}