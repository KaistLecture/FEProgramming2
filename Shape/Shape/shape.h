#pragma once

class Shape {
protected:
	double a_;
public:
	Shape(double a) : a_(a) {}
	virtual double area() = 0;
};

class Square : public Shape{
public:
	Square(double a);
	virtual double area();
};

class Rect : public Shape {
private:
	double b_;
public:
	Rect(double a, double b);
	virtual double area(); //오버라이딩
};