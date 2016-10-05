
#include <iostream>
#include <string>

int add(double x, double y) {
	return x + y;
}
int add(double x, double y, double z) {
	return x * y + z;
}

//Class
class Rect {
	//����Լ�, �޼ҵ�
	//������
public:
	Rect(double x, double y, std::string color) :
		x_(x), y_(y), color_(color) {}
	~Rect() { std::cout << "�Ҹ���ȣ��" << x_ << std::endl; }
	double getX() { return x_; }
	void setX(double x) { x_ = x; }
	double getY() { return y_; }
	std::string getColor() { return color_; }
	double area() { return x_*y_; }
private:
	//�������, �Ӽ�,
	double x_, y_;
	std::string color_;
};

int main() {	
	//function overloading
	std::cout << add(1, 2) << std::endl;
	std::cout << add(1, 2, 3) << std::endl;
	
	Rect a(5, 3, "black");
	Rect b(2, 6, "white");
	Rect c = Rect(4, 7, "green");

	a.setX(10);
	std::cout << "x=" << a.getX() << std::endl;
	std::cout << "y=" << a.getY() << std::endl;
	std::cout << "color=" << a.getColor() << std::endl;
	for (int i = 0; i < 10; ++i) {
		a.setX(i + 1);
		std::cout << "area=" << a.area() << std::endl;
	}

	//Member variables, member functions
	//Constructor & Destructor
	//public, private, protected
	
	return 0;
}