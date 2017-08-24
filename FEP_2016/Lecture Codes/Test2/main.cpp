//Lecture 2

#include <iostream>
#include <cmath>
#include <string>

double foo(int , double y, std::string str); //함수원형, prototype
double pv(double r=0.04, double t=1.0);

int main() {
	//static 변수: 함수 블럭을 벗어나도 메모리에서 지워지지 않고 값을 기억하는 변수
	std::cout << foo(0, 0, "") << std::endl;
	std::cout << foo(0, 0, "") << std::endl;
	std::cout << foo(0, 0, "") << std::endl;
	std::cout << foo(0, 0, "") << std::endl;

	//변수의 유효범위
	int a = 10;
	{
		int a = 100;   //local영역의 변수가 덮어씀
		std::cout << a << std::endl;
	}
	std::cout << a << std::endl;

	//함수의 호출
	int g = foo(10, 5.5, "TEST");
	std::cout << g << std::endl;

	//boolean type
	bool b = false;
	std::cout << b << std::endl;

	//const
	const double PI = 3.141592;
	std::cout << PI << std::endl;

	//연산자
	int d = 10 % 3; //나머지
	
	//비교연산자
	bool tf = !(10 > 20);
	std::cout << tf << std::endl;

	//cin
	// PV 계산기
	double r = 0.03, t = 1.0;
	std::cout << "rate = ";
	std::cin >> r;
	std::cout << "mat = ";
	std::cin >> t;
	std::cout << "PV = " <<
		pv(r, t) << std::endl;
	std::cout << pv() << std::endl;

	//function
	//default argument
	//local global static
	
	//structure

	//enumerator


	//if else
	bool temp = 10 > 20;
	if (temp) {
		//true
		!temp;
		std::cout << "true" << std::endl;
	}
	else if (30>20) {
		std::cout << "one more chance" << std::endl;
	}
	else {
		!temp;
		//not true
		std::cout << "false" << std::endl;
	}

	//? operator
	//call option
	//max(s-k,0)
	double s = 100,  k = 90;
	double payoff = (s > k) ? s - k : 0;
	//if (s > k) 
	//	payoff = s - k;
	//else 
	//	payoff = 0;

	std::cout << payoff << std::endl;
	
	//switch case

	//for loop
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			double x = pv();
			std::cout << j << "% " <<
				i + 1 << ")" << pv(j/100.0, i + 1) 
				<< std::endl;
		}
	}
	
	//while loop
	int n = 0;
	while (true) {
		std::cout << n << std::endl;
		if (n == 20)
			continue; //or break;
		++n;
	}

	//do while loop

	//continue break

	return 0;
}

double foo(int x, double y, std::string str) {
	x *= 3;
	std::cout << str << "(" << x + y << ")" << std::endl;
	static int n = 0;
	return ++n;
}

//Global 변수
int a = 10;

double pv(double r, double t) {
	double p = exp(-r*t);
	return p*a;
}
