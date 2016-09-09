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
	//정수형 변수 타입
	cout << sizeof(unsigned int) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(long long) << endl;
	
	short a = 0;  //a:정수
	std::cout << a << std::endl;
	std::cout << a - 1 << std::endl;

	//정수 범위
	unsigned short n = 65535; //2바이트: 0부터 2^16-1=65535 까지 가능
	unsigned short m = n + 1; //65,536이 아니라 0이 됨
	cout << n << " + 1 = " << m << endl;   

	short p = 32767; //2바이트: -32768~+32767 까지 가능
	short q = p + 1; //32768이 아니라 -32768이 됨
	cout << p << " + 1 = " << q << endl;

	//int와 unsigned int는 4바이트 (=32비트)  2^32 가지 숫자 표현가능
	//int: -2^31 ~ +2^31-1 까지 가능
	//unsigned int: 0 ~ +2^32-1 까지 가능

	//실수형 변수 타입
	double b = 0.123;  float c = 0.123;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;

	//문자와 문자열
	char d = 'A';
	std::string s = "ABCDE";
	cout << d << endl;
	cout << s << endl;

	//지수승
	int x = std::pow(2, 3);
	cout << x << endl;

	//연산자
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

	//  ** 또는 // 같은 연산자는 없습니다.

	cout << ++a << endl;
	cout << --a << endl;

	cout << a++ << endl;
	cout << a-- << endl;

	//연산자 추가
	int y = 10, z = 3;
	std::cout << y%z << std::endl;    // %: 나머지를 계산함
	std::cout << y / z << std::endl;  // 이렇게 하면 몫이 계산됨 (정수와 정수 연산 결과는 소수 버리고 정수만)

	return 0;
 }