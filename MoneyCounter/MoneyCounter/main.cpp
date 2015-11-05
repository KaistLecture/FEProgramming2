#include <iostream>
#define NUM 9

using namespace std;

int* counter(double amt, int* unit) {
	int* n = new int[NUM];
	int iamt = int(amt * 100 + 0.5);  //반올림: 0.5 더한뒤에 소수점 버림을 함
	for (unsigned int i = 0; i < NUM; ++i) {
		n[i] = iamt / unit[i]; // 몫: int 나누기 int
		iamt %= unit[i];       // 나머지
	}
	return n;
}


int main() {	
	double amt;
	cout << "Amount = ";
	cin >> amt;

	int unit[NUM] = { 2000, 1000, 500, 200, 100, 25, 10, 5, 1 };	
	char* header[NUM] = { "20D", "10D", "5D", "2D", "1D", "25C", "10C", "5C", "1C" };
	int* rst = counter(amt, unit);
	for (unsigned int i = 0; i < NUM; ++i) {
		cout << header[i] << " = " << rst[i] << endl;
	}
	delete[] rst;
	return 0;
}