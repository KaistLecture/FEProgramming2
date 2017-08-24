#pragma once
#include <iostream>
#include <string>

//Class
class Rect {
	//public 영역의 변수와 함수는 클래스 외부에서 직접 접근이 가능함
public:
	//멤버함수, 메소드
	//생성자
	Rect() {};
	Rect(double x, double y, std::string color);
	//copy constructor
	Rect(const Rect& rhs);
	//assinment operator
	Rect& operator=(const Rect& rhs);
	//소멸자
	~Rect();

	//get method: 멤버변수는 일반적으로 private 접근권한으로 설정
	//class 외부에서 멤버변수의 값을 이용하거나 변경할 때, get/set 함수를 이용함
	double getX() const { return x_; }
	double getY() const { return y_; }
	std::string getColor()const { return color_; }
	//set method
	void setX(double x) { x_ = x; }

	//넓이 계산 함수
	double area() const;

	//private 영역의 변수와 함수는 클래스 외부에서 직접 접근이 불가함
private:
	//멤버변수, 속성,
	double x_, y_;
	std::string color_;
};