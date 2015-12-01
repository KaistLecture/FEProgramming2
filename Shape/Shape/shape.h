#pragma once

class Square {
protected:
	double a_;
public:
	Square(double a);
	double area();
};

class Rect : public Square {
private:
	double b_;
public:
	Rect(double a, double b);
	double area(); //오버라이딩
};