
#include <iostream>
#include <vector>

class Point {
private:
	double x_;
	double y_;
public:
	Point(double x, double y)
		: x_(x), y_(y) {}
	double getX() { return x_; }
	double getY() { return y_; }
	double distance(Point& p) {
		double temp =
			std::pow((this->x_ - p.getX()),2) +
			std::pow((this->y_ - p.getY()),2);
		return std::sqrt(temp);
	}
};

std::vector<double> calcRect(Point& p1, Point& p2) {
	std::vector<double> ret(2);
	double x1 = p1.getX();
	double y1 = p1.getY();
	double x2 = p2.getX();
	double y2 = p2.getY();
	ret[0] = 2 * (std::abs(x1 - x2) + std::abs(y1 - y2));
	ret[1] = std::abs(x1 - x2) * std::abs(y1 - y2);
	return ret;
}


int main() {
	Point A(1, 10);
	Point B(3, 4);
	double d1 = A.distance(B);
	double d2 = B.distance(A);
	std::vector<double> r = calcRect(A, B);

	std::cout << "distance from A = " << d1 << std::endl;
	std::cout << "distance from B = " << d2 << std::endl;
	std::cout << "perimeter = " << r[0] << std::endl;
	std::cout << "area = " << r[1] << std::endl;
}



//클래스 예제
class Stock {
private:
	int shares;
	double price;
	double tot_value;
	void calc_tot() { 
		tot_value = shares*price;
	}
public:
	Stock(int s, double p) : shares(s), price(p) {
		calc_tot();
	}
	double get_tot() {
		return tot_value;
	}
};

int main2() {
	//초기화 생성자
	Stock a(10, 120);
	double t = a.get_tot();
	std::cout << t << std::endl;
	return 0;
}



//함수 예제
int test(int* n) {
	return n[0];
}

int f(int a, int b) {return a;}
int f(int a, int b, int c) { return c; }

int main3() {
	//int a = 10;
	f(1, 2);
	{
		int a = 20;
		std::cout << a << std::endl;
	}
	int a[10] = { 10 };
	int n = test(a);
	std::cout << n << std::endl;
	return 0;
}
