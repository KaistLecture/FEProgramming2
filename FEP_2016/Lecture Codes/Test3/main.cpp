//Lecture 3
#include <iostream>
#include <vector>
#include <random>
#include "normal.h" //사용자정의 Header 파일 사용

#define MESSAGE(x) std::cout<<"----"x"----"<<std::endl;

#define XYZ 10		    //MACRO 변수: 이후 소스 코드에서 모든 XYZ를 10으로 치환함
#define F(x) ((x)*(x))  //MACRO 함수: 소스코드 변환 후 컴파일함. 괄호를 앞뒤로 붙여야 원하는 함수가 됨.
#define LENGTH(x) sizeof(x)/sizeof(x[0])  //배열의 길이를  구하는 매크로 함수 (매크로 함수 예시)
#define N 3

#ifndef WXYZ      //전처리기: WXYZ라는 매크로변수가 정의되어 있지 않으면, 아래 소스코드를 컴파일함
double foo() {
	return 10;
}
#else             // WXYZ라는 매크로 변수가 정의되어 있으면, 아래 소스코드를 컴파일함
double foo() {
	return 20;
}
#endif

typedef double Yield;   //사용자 정의 데이터타입 : Yield는 double형과 동일함. 타입명의 길이가 길어서 간단히 표현하거나, 변수의 의미를 추론하기 쉽도록 사용함.

double sumArr(double arr[], int n) {  //배열 Array를 함수의 인자로 넘길 때, 반드시 array의 길이를 함께 넘겨줘야 함수 내에서 array의 길이를 사용할 수 있음.
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
	}
	return sum;     //입력받은 array의 원소의 합을 계산하는 함수
}

typedef std::vector<double> DV;  //앞에서 언급한 바와 같이 타입명의 길이가 길어서 간단하게 DV라고 재정의함
double sumVec(DV vec) {    //double sumVec(std::vector<double> vec) 와 동일함
	double sum = 0;
	for (int i = 0; i < vec.size(); ++i) {
		sum += vec[i];
	}
	return sum;    //입력받은 vector의 원소의 합을 계산하는 함수 (array와 다르게 vector의 길이를 인자로 함께 넘겨줄 필요가 없음: vec.size()를 사용)
}

double add(double& x, double y) {  //reference변수 : 타입명 뒤에 &를 붙임. pass-by-reference 
	x++;
	y++;
	return x + y;
}


int main() {
	MESSAGE("전처리기 조건부 컴파일")
	std::cout << foo() << std::endl; //전처리기의 #ifndef 의 조건에 따라서 foo() 함수가 달라짐: WXYZ가 정의되어 있지 않다면 10을 리턴하는 함수로 컴파일됨.

	//&& ||
	MESSAGE("&& || 조건")
	if (1 == 2 && 10 > 5)  //and 조건 (& 한개를 사용하지 않도록 주의)
		std::cout << "True" << std::endl;
	else
		std::cout << F(1 + 3) << std::endl;  //macro함수에 괄호를 넣어야하는 이유


	//Normal Distribution
	MESSAGE("정규분포함수")
	Yield p = normcdf(0);   //누적정규분포함수는 error function을 이용함
	std::cout << p << std::endl;


	//array
	MESSAGE("Array의 사용")
	double arr[][2] = { {0,1},{2,3},{4,5} };  //2차원 배열
	//arr[0] ~ arr[4]
	for (int i = 0; i < N; ++i)
		std::cout << arr[i][0] << std::endl;
	
	double arr2[3] = { 4,5,6 };
	std::cout << sizeof(arr2) / sizeof(int) << std::endl;   //배열의 원소개수 구하기
	std::cout << LENGTH(arr2) << std::endl;                 //배열 원소개수를 macro 함수로 구하기
	std::cout << "sum=" << sumArr(arr2,3) << std::endl;     //배열의 원소의 합을 구하는 함수 이용

	//vector
	MESSAGE("Vector의 사용")
	std::vector<int> vec;  //vector는 템플릿. vector에 담기는 데이터의 타입을 부동호 사이에 넣어야 함
	vec.push_back(10);  //vector 끝에 데이터 추가. append와 동일
	vec.push_back(20);
	vec.push_back(30);
	std::cout << "size = " << vec.size() << std::endl;  //vector 원소 개수를 구하는 함수
	vec.push_back(40);
	vec.push_back(50);
	std::cout << "size = " << vec.size() << std::endl;

	std::vector<double> v2(10,5);  //원소 10개 짜리 vector를 생성하고 모든 값을 5로 초기화함
	for (int i = 0; i < v2.size(); ++i) {
		std::cout << v2[i] << std::endl;
	}
	std::cout << "sum = " << sumVec(v2) << std::endl;  //vector 원소의 합을 구하는 함수 출력값은 50임
	
	double temp[5] = { 0,1,2,3,4 };  //vector 초기화 방법
	std::vector<double> vec3(temp, temp + 3);  //array를 가지고 초기화 array 변수 이름과 초기화하려는 원소의 개수를 입력
	std::vector<double> vec4 = { 1,2,3 };  //이런 방법도 가능!!! C++ 11이후 추가된 기능
	for (int i = 0; i < vec3.size(); ++i) {
		std::cout << vec3[i] << std::endl;
	}
	std::cout << "sum = " << sumVec(vec3) << std::endl;
	
	//reference
	MESSAGE("Reference 변수")
	int x = 10;
	std::cout << x << std::endl;
	std::cout << &x << std::endl;  //x변수의 주소를 출력함

	int& y = x;  //y변수는 x의 reference임
	++y;  //y를 더하면 x 역시 더해짐 (같은 주소를 참고하고 있으므로)
	std::cout << x << std::endl;
	std::cout << &y << std::endl; // x와 같은 주소가 출력됨

	int z = 20;
	y = z;  //reference 변수는 중간에 다른 변수를 참조할 수 없음. 이 명령은 y변수에 z의 값을 복사해서 대입함
	std::cout << x << "\t" << y << "\t" << z << std::endl;
	std::cout << &y << std::endl;
	std::cout << &z << std::endl; //z의 주소는 x, y의 주소와는 다름
	
	MESSAGE("Call by reference")
	double x1 = 0;
	double x2 = 0;
	std::cout << add(x1, x2) << std::endl;
	std::cout << x1 << std::endl;  //x1은 pass-by-reference이므로 함수 내에서 1이 더해져서 값이 1로 변경
	std::cout << x2 << std::endl;  //x2는 pass-by-value 이므로 함수에 복사된 값이 전달되어 함수 내에서 연산과는 독립됨

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