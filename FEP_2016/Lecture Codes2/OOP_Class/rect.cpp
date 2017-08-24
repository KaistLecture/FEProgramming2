#include "rect.h"


Rect::Rect(double x, double y, std::string color) :
	x_(x), y_(y), color_(color) {
	std::cout << "--생성자호출--!!!" << std::endl;
	std::cout << "x=" << x_ << "\t" << "y=" << y_ << "\t" << "color=" << color_ << "\n\n";
}

Rect::Rect(const Rect& rhs) {
	std::cout << "copy constructor!!!" << std::endl;
	x_ = rhs.x_;
	y_ = rhs.y_;
	color_ = rhs.color_;
}
//assinment operator
Rect& Rect::operator=(const Rect& rhs) {
	std::cout << "assignment" << std::endl;
	x_ = rhs.x_;
	y_ = rhs.y_;
	color_ = rhs.color_;
	return *this;
}

Rect::~Rect() {
	std::cout << "--소멸자호출--!!!" << std::endl;
	std::cout << "x=" << x_ << "\t" << "y=" << y_ << "\t" << "color=" << color_ << "\n\n";
}

double Rect::area() const { 
	return x_*y_; 
}