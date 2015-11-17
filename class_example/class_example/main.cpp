
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
	std::vector<double> ret;
	return ret;
}

int main() {
	Point A(1, 10);
	Point B(3, 4);
	double d1 = A.distance(B);
	double d2 = B.distance(A);
	std::vector<double> r = calcRect(A, B);
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;

}

/*
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

int main() {
	//초기화 생성자
	Stock a(10, 120);
	double t = a.get_tot();
	std::cout << t << std::endl;
	return 0;
}





int test(int* n) {
	return n[0];
}


int f(int a, int b) {return a;}
int f(int a, int b, int c) { return c; }

int test_main() {
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
*/