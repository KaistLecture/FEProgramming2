//Lecture 1

#include <iostream>
#include <string>

namespace TEST {
	int a = 30;
}
using namespace std;

int main(void) {

	//comment

	/*
	multiline comment
	*/
	//������ ���� Ÿ��
	cout << sizeof(unsigned int) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(long long) << endl;
	
	short a = 0;  //a:����
	std::cout << a << std::endl;
	std::cout << a - 1 << std::endl;

	//���� ����
	unsigned short n = 65535; //2����Ʈ: 0���� 2^16-1=65535 ���� ����
	unsigned short m = n + 1; //65,536�� �ƴ϶� 0�� ��
	cout << n << " + 1 = " << m << endl;   

	short p = 32767; //2����Ʈ: -32768~+32767 ���� ����
	short q = p + 1; //32768�� �ƴ϶� -32768�� ��
	cout << p << " + 1 = " << q << endl;

	//int�� unsigned int�� 4����Ʈ (=32��Ʈ)  2^32 ���� ���� ǥ������
	//int: -2^31 ~ +2^31-1 ���� ����
	//unsigned int: 0 ~ +2^32-1 ���� ����

	//�Ǽ��� ���� Ÿ��
	double b = 0.123;  float c = 0.123;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;

	//���ڿ� ���ڿ�
	char d = 'A';
	std::string s = "ABCDE";
	cout << d << endl;
	cout << s << endl;

	//������
	int x = std::pow(2, 3);
	cout << x << endl;

	//������
	a = 10;
	a += 5;// a = a + 5;
	a -= 10; // a = a-10;
	a *= 2;
	int f = 3;
	double e = a / (double)f;
	cout << e << endl;

	cout << a << endl;
	a++;  //a=a+1
	cout << a << endl;
	a--;  //a=a-1
	cout << a << endl;

	//  ** �Ǵ� // ���� �����ڴ� �����ϴ�.

	cout << ++a << endl;
	cout << --a << endl;

	cout << a++ << endl;
	cout << a-- << endl;

	//������ �߰�
	int y = 10, z = 3;
	std::cout << y%z << std::endl;    // %: �������� �����
	std::cout << y / z << std::endl;  // �̷��� �ϸ� ���� ���� (������ ���� ���� ����� �Ҽ� ������ ������)

	return 0;
 }