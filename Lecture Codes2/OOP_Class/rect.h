#pragma once
#include <iostream>
#include <string>

//Class
class Rect {
	//public ������ ������ �Լ��� Ŭ���� �ܺο��� ���� ������ ������
public:
	//����Լ�, �޼ҵ�
	//������
	Rect() {};
	Rect(double x, double y, std::string color);
	//copy constructor
	Rect(const Rect& rhs);
	//assinment operator
	Rect& operator=(const Rect& rhs);
	//�Ҹ���
	~Rect();

	//get method: ��������� �Ϲ������� private ���ٱ������� ����
	//class �ܺο��� ��������� ���� �̿��ϰų� ������ ��, get/set �Լ��� �̿���
	double getX() const { return x_; }
	double getY() const { return y_; }
	std::string getColor()const { return color_; }
	//set method
	void setX(double x) { x_ = x; }

	//���� ��� �Լ�
	double area() const;

	//private ������ ������ �Լ��� Ŭ���� �ܺο��� ���� ������ �Ұ���
private:
	//�������, �Ӽ�,
	double x_, y_;
	std::string color_;
};