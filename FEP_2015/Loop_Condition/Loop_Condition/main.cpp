
#include <iostream>
#include <vector>
enum WeekDay {Sun,Mon,Tue,Wed,Thu,Fri,Sat};

void f(WeekDay day) {
	if (day == Sun)
		std::cout << "It's Sunday" << std::endl;
}

int main() {
	//do while
	int s, e;
	bool a = false;
	do {
		if (a)
			std::cout << "ERROR" << std::endl;		
		std::cin >> s;
		std::cin >> e;
		a = (s > e);
	} while (a);


	//vector
	std::vector<int> vi;
	std::cout << vi.size() << std::endl;
	vi.push_back(10);
	vi.push_back(5);
	std::cout << vi.size() << std::endl;
	std::cout << vi[1] << std::endl;

	//array vector
	std::vector<int*> test;
	int* temp = new int[10];
	test.push_back(temp);
	test[0][5];
	delete[] test[0];

	//continue break
	for (int i = 1; i < 10; ++i) {
		if (i % 4 == 0) {
			std::cout << "Lucky number" << std::endl;
			continue;
		}
		std::cout << i << std::endl;
	}

	//do while
	int input;
	do {
		std::cin >> input;
	} while (input != 7);
	std::cout << input << std::endl;


	//for loop
	int i, j;
	for (i=0, j=10; i<=j ; i++, j-- ) {
		std::cout << i << " " << j << std::endl;
	}
	
	return 0;
}