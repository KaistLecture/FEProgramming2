
#include <iostream>
#include <string>

//function overloading: �Լ��� signature �� �ٸ��� �ϸ� ���� �Լ� �̸����� �ٸ� �Լ��� ����� ����
double add(double x, double y) {
	return x + y;
}
double add(double x, double y, double z) {
	return x * y + z;
}

//Class
class Rect {
	//public ������ ������ �Լ��� Ŭ���� �ܺο��� ���� ������ ������
public:
	//����Լ�, �޼ҵ�
	//������
	Rect() {};
	Rect(double x, double y, std::string color) :
		x_(x), y_(y), color_(color) {
		std::cout << "--������ȣ��--" << std::endl;
		std::cout << "x=" << x_ << "\t" << "y=" << y_ << "\t" << "color=" << color_ << "\n\n";
	}
	//�Ҹ���
	~Rect() { 
		std::cout << "--�Ҹ���ȣ��--" << std::endl;
		std::cout << "x=" << x_ << "\t" << "y=" << y_ << "\t" << "color=" << color_ << "\n\n";
	}

	//get method: ��������� �Ϲ������� private ���ٱ������� ����
	//class �ܺο��� ��������� ���� �̿��ϰų� ������ ��, get/set �Լ��� �̿���
	double getX() const { return x_; }
	double getY() const { return y_; }
	std::string getColor()const { return color_; }
	//set method
	void setX(double x) { x_ = x; }

	//���� ��� �Լ�
	double area() const { return x_*y_; }

	//private ������ ������ �Լ��� Ŭ���� �ܺο��� ���� ������ �Ұ���
private:
	//�������, �Ӽ�,
	double x_, y_;
	std::string color_;
};

void printRect(Rect& r) { //reference�� ���� �ƴ� ��� ����
	std::cout << "x=" << r.getX() << "\n" << "y=" << r.getY() << "\n" << "color=" << r.getColor() << "\n\n";
}

int main() {	
	//function overloading
	std::cout << add(1, 2) << std::endl;
	std::cout << add(1, 2, 3) << std::endl;	

	std::cout << "Class" << std::endl;

	Rect a(5, 3, "black");         //��ü object ����: �����ڰ� ȣ���
	Rect b(2, 6, "white");         //�� �ٸ� ��ü ����: a�ʹ� ������ instance�� ������
	Rect c = Rect(4, 7, "green");  //�����ڰ� ȣ��Ǵ� �ٸ� ���
	
	Rect d;
	d = c;

	std::cout << "get/set �Լ� �̿�" << std::endl;
	a.setX(10);  //set �Լ��� �̿��ؼ� ��ü a�� x_������ ���� ������
	std::cout << "x=" << a.getX() << std::endl;
	std::cout << "y=" << a.getY() << std::endl;
	std::cout << "color=" << a.getColor() << std::endl;
	for (int i = 0; i < 10; ++i) {
		a.setX(i + 1);
		std::cout << "area=" << a.area() << std::endl;
	}
	
	std::cout << "\n�Լ��� �̿��� ���" << std::endl;
	printRect(b);
	printRect(c);
	printRect(d);
	
	//default constructor
	Rect n;
	printRect(n);

	//copy constructor
	Rect e(a);
	printRect(e);
	
	//copy assignment
	n = a;
	printRect(n);

	//struct


	return 0;

	//�Լ��� ����Ǹ鼭 ��ü�� �Ҹ��� ȣ��
	//������ �������� �Ҹ��: stack �޸��� Ư��
}