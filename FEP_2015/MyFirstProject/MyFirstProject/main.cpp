// 주석..
/*주석
주석
*/

#include <iostream>
int main()
{
	using namespace std;
	cout << "Hello" << endl;

	int age = 38;
	unsigned int a = 10;

	a = a + 1;
	a++;
	++a;
	cout << ++a << endl;

	a = a + 3;
	a += 3;

	a = a - 1;
	a--;
	--a;
	a -= 3;

	a = a * 2;
	a *= 2;
	
	a /= 2;
	a = a % 3;

	int n = pow(3,5);

	int x = 10;
	int z = 3;
	double y = (double)x / z;
	cout << y << endl;

	//cout << "input=";
	//int in;
	//cin >> in;
	//cout << in*in << endl;

	unsigned int max = pow(2, 32) - 1;
	cout << max << endl;
	cout << ++max << endl;

	int arr[3] = { 10, 5, 15 };
	double arrd[] = { 1.2, 3.2, 4.5, 6.7 };
	cout << sizeof(arrd)/sizeof(double) << endl;

	double s[5] = { 1, 3 };
	cout << s[1] << " " << s[4] << endl;


	//arr[0] = 10;
	//arr[1] = 5;
	//arr[2] = 15;





	return 0;
}
