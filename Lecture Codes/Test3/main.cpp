//Lecture 3
#include <iostream>
#include <vector>
#include <random>
#include "normal.h" //��������� Header ���� ���

#define MESSAGE(x) std::cout<<"----"x"----"<<std::endl;

#define XYZ 10		    //MACRO ����: ���� �ҽ� �ڵ忡�� ��� XYZ�� 10���� ġȯ��
#define F(x) ((x)*(x))  //MACRO �Լ�: �ҽ��ڵ� ��ȯ �� ��������. ��ȣ�� �յڷ� �ٿ��� ���ϴ� �Լ��� ��.
#define LENGTH(x) sizeof(x)/sizeof(x[0])  //�迭�� ���̸�  ���ϴ� ��ũ�� �Լ� (��ũ�� �Լ� ����)
#define N 3

#ifndef WXYZ      //��ó����: WXYZ��� ��ũ�κ����� ���ǵǾ� ���� ������, �Ʒ� �ҽ��ڵ带 ��������
double foo() {
	return 10;
}
#else             // WXYZ��� ��ũ�� ������ ���ǵǾ� ������, �Ʒ� �ҽ��ڵ带 ��������
double foo() {
	return 20;
}
#endif

typedef double Yield;   //����� ���� ������Ÿ�� : Yield�� double���� ������. Ÿ�Ը��� ���̰� �� ������ ǥ���ϰų�, ������ �ǹ̸� �߷��ϱ� ������ �����.

double sumArr(double arr[], int n) {  //�迭 Array�� �Լ��� ���ڷ� �ѱ� ��, �ݵ�� array�� ���̸� �Բ� �Ѱ���� �Լ� ������ array�� ���̸� ����� �� ����.
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
	}
	return sum;     //�Է¹��� array�� ������ ���� ����ϴ� �Լ�
}

typedef std::vector<double> DV;  //�տ��� ����� �ٿ� ���� Ÿ�Ը��� ���̰� �� �����ϰ� DV��� ��������
double sumVec(DV vec) {    //double sumVec(std::vector<double> vec) �� ������
	double sum = 0;
	for (int i = 0; i < vec.size(); ++i) {
		sum += vec[i];
	}
	return sum;    //�Է¹��� vector�� ������ ���� ����ϴ� �Լ� (array�� �ٸ��� vector�� ���̸� ���ڷ� �Բ� �Ѱ��� �ʿ䰡 ����: vec.size()�� ���)
}

double add(double& x, double y) {  //reference���� : Ÿ�Ը� �ڿ� &�� ����. pass-by-reference 
	x++;
	y++;
	return x + y;
}


int main() {
	MESSAGE("��ó���� ���Ǻ� ������")
	std::cout << foo() << std::endl; //��ó������ #ifndef �� ���ǿ� ���� foo() �Լ��� �޶���: WXYZ�� ���ǵǾ� ���� �ʴٸ� 10�� �����ϴ� �Լ��� �����ϵ�.

	//&& ||
	MESSAGE("&& || ����")
	if (1 == 2 && 10 > 5)  //and ���� (& �Ѱ��� ������� �ʵ��� ����)
		std::cout << "True" << std::endl;
	else
		std::cout << F(1 + 3) << std::endl;  //macro�Լ��� ��ȣ�� �־���ϴ� ����


	//Normal Distribution
	MESSAGE("���Ժ����Լ�")
	Yield p = normcdf(0);   //�������Ժ����Լ��� error function�� �̿���
	std::cout << p << std::endl;


	//array
	MESSAGE("Array�� ���")
	double arr[][2] = { {0,1},{2,3},{4,5} };  //2���� �迭
	//arr[0] ~ arr[4]
	for (int i = 0; i < N; ++i)
		std::cout << arr[i][0] << std::endl;
	
	double arr2[3] = { 4,5,6 };
	std::cout << sizeof(arr2) / sizeof(int) << std::endl;   //�迭�� ���Ұ��� ���ϱ�
	std::cout << LENGTH(arr2) << std::endl;                 //�迭 ���Ұ����� macro �Լ��� ���ϱ�
	std::cout << "sum=" << sumArr(arr2,3) << std::endl;     //�迭�� ������ ���� ���ϴ� �Լ� �̿�

	//vector
	MESSAGE("Vector�� ���")
	std::vector<int> vec;  //vector�� ���ø�. vector�� ���� �������� Ÿ���� �ε�ȣ ���̿� �־�� ��
	vec.push_back(10);  //vector ���� ������ �߰�. append�� ����
	vec.push_back(20);
	vec.push_back(30);
	std::cout << "size = " << vec.size() << std::endl;  //vector ���� ������ ���ϴ� �Լ�
	vec.push_back(40);
	vec.push_back(50);
	std::cout << "size = " << vec.size() << std::endl;

	std::vector<double> v2(10,5);  //���� 10�� ¥�� vector�� �����ϰ� ��� ���� 5�� �ʱ�ȭ��
	for (int i = 0; i < v2.size(); ++i) {
		std::cout << v2[i] << std::endl;
	}
	std::cout << "sum = " << sumVec(v2) << std::endl;  //vector ������ ���� ���ϴ� �Լ� ��°��� 50��
	
	double temp[5] = { 0,1,2,3,4 };  //vector �ʱ�ȭ ���
	std::vector<double> vec3(temp, temp + 3);  //array�� ������ �ʱ�ȭ array ���� �̸��� �ʱ�ȭ�Ϸ��� ������ ������ �Է�
	std::vector<double> vec4 = { 1,2,3 };  //�̷� ����� ����!!! C++ 11���� �߰��� ���
	for (int i = 0; i < vec3.size(); ++i) {
		std::cout << vec3[i] << std::endl;
	}
	std::cout << "sum = " << sumVec(vec3) << std::endl;
	
	//reference
	MESSAGE("Reference ����")
	int x = 10;
	std::cout << x << std::endl;
	std::cout << &x << std::endl;  //x������ �ּҸ� �����

	int& y = x;  //y������ x�� reference��
	++y;  //y�� ���ϸ� x ���� ������ (���� �ּҸ� �����ϰ� �����Ƿ�)
	std::cout << x << std::endl;
	std::cout << &y << std::endl; // x�� ���� �ּҰ� ��µ�

	int z = 20;
	y = z;  //reference ������ �߰��� �ٸ� ������ ������ �� ����. �� ����� y������ z�� ���� �����ؼ� ������
	std::cout << x << "\t" << y << "\t" << z << std::endl;
	std::cout << &y << std::endl;
	std::cout << &z << std::endl; //z�� �ּҴ� x, y�� �ּҿʹ� �ٸ�
	
	MESSAGE("Call by reference")
	double x1 = 0;
	double x2 = 0;
	std::cout << add(x1, x2) << std::endl;
	std::cout << x1 << std::endl;  //x1�� pass-by-reference�̹Ƿ� �Լ� ������ 1�� �������� ���� 1�� ����
	std::cout << x2 << std::endl;  //x2�� pass-by-value �̹Ƿ� �Լ��� ����� ���� ���޵Ǿ� �Լ� ������ ������� ������

	//random normal dist.
	MESSAGE("normal random number generation")
	std::mt19937_64 gen;
	std::normal_distribution<double> engine;
	for (int i = 0; i < 3; ++i) {
		double rn = engine(gen);
		std::cout << rn << std::endl;
	}


	return 0;


}