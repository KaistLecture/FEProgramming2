#pragma once
#include <string>

class Shape {
public:
	Shape(std::string color)
		: color_(color) {}

	virtual double area() = 0;
	virtual double length() = 0;
	void setColor(std::string color);
	std::string getColor();
protected:
	std::string color_;
};

class Circle : public Shape {
public:
	Circle(double r, std::string color)
		: Shape(color), r_(r) {}
	double area();
	double length() {
		return 2 * 3.14 * r_;
	}
private:
	double r_;
};

class Rect : public Shape {
public:
	Rect(double w, double h, std::string color)
		: w_(w), h_(h), Shape(color) {}
	double area() { return w_*h_; }
	double length() { return 2 * (w_ + h_); }
private:
	double w_, h_;
};
