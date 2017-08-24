
#include <iostream>
#include <string>
#include "rect.h"

//function overloading: 함수의 signature 를 다르게 하면 같은 함수 이름으로 다른 함수를 만들수 있음
double add(double x, double y) {
	return x + y;
}
double add(double x, double y, double z) {
	return x * y + z;
}

void printRect(Rect r) { //reference인 경우와 아닌 경우 차이
	std::cout << "x=" << r.getX() << "\n" << "y=" << r.getY() << "\n" << "color=" << r.getColor() << "\n\n";
}

int main() {	
	//function overloading
	std::cout << add(1, 2) << std::endl;
	std::cout << add(1, 2, 3) << std::endl;	

	std::cout << "Class" << std::endl;

	Rect a(5, 3, "black");         //객체 object 생성: 생성자가 호출됨
	Rect b(2, 6, "white");         //또 다른 객체 생성: a와는 별개의 instance가 생성됨
	Rect c = Rect(4, 7, "green");  //생성자가 호출되는 다른 방식
	
	Rect d;
	d = c;

	std::cout << "get/set 함수 이용" << std::endl;
	a.setX(10);  //set 함수를 이용해서 객체 a의 x_변수의 값을 변경함
	std::cout << "x=" << a.getX() << std::endl;
	std::cout << "y=" << a.getY() << std::endl;
	std::cout << "color=" << a.getColor() << std::endl;
	for (int i = 0; i < 10; ++i) {
		a.setX(i + 1);
		std::cout << "area=" << a.area() << std::endl;
	}
	
	std::cout << "\n함수를 이용한 출력" << std::endl;
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

	//함수가 종료되면서 객체의 소멸자 호출
	//생성된 역순으로 소멸됨: stack 메모리의 특성
}