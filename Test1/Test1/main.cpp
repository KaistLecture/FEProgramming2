#include <iostream>
#include <string>

namespace TEST {
	int a = 30;
}
using namespace std;

void main(void) {
	//comment

	/*
	multiline comment
	*/
	cout << sizeof(unsigned int) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(long long) << endl;
	

	short a = 0;  //a:Á¤¼ö
	std::cout << a << std::endl;
	std::cout << a - 1 << std::endl;

	double b = 0.123;  float c = 0.123;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;

	char d = 'A';
	std::string s = "ABCDE";
	cout << d << endl;
	cout << s << endl;

	int x = std::pow(2, 3);
	cout << x << endl;

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

	cout << ++a << endl;
	cout << --a << endl;

	cout << a++ << endl;
	cout << a-- << endl;


 }