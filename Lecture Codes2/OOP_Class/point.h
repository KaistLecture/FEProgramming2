#pragma once
#include <vector>

class Point {
	double x_, y_;
public:
	double getX() const { return x_; }
	double getY() const { return y_; }
	Point(double x, double y) :
		x_(x), y_(y) {}
	double distance(const Point& p);
};

std::vector<double> calcRect(Point& p1, Point& p2);