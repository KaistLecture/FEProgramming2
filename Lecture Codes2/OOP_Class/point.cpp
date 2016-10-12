#include "point.h"
#include <cmath>
double Point::distance(const Point& p) {
	double dx = x_ - p.x_;
	double dy = y_ - p.y_;
	return sqrt(dx*dx + dy*dy);
}

std::vector<double> calcRect(Point& p1, Point& p2) {
	double area, perimeter;
	double dx = abs(p1.getX() - p2.getX());
	double dy = abs(p1.getY() - p2.getY());
	area = dx*dy;
	perimeter = 2*(dx+dy);
	std::vector<double> res;
	res.push_back(perimeter);
	res.push_back(area);
	return res;
}