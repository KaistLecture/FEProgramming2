#include <iostream>
#include "point.h"

int main() {
	Point start(2, 5);
	Point end = Point(5, 1);
	double dist = start.distance(end);
	std::cout << "distance = " << dist << std::endl;
	std::cout << "distance = " << end.distance(start)
		<< std::endl;
	std::vector<double> res = calcRect(start, end);
	std::cout << "perimeter = " << res[0] << std::endl;
	std::cout << "area = " << res[1] << std::endl;
	return 0;
}