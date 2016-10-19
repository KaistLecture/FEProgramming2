#include <iostream>
#include <random>
#include <cmath>
#include <chrono>

class Die {
public:
	int cast() {
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::mt19937 gen(seed);
		std::uniform_int_distribution<int> engine(1,6);
		return engine(gen);
	}
};

class Game : public Die {  //Is-A ����� public ������� Die�� ����� Game���� ����ϵ��� ��.
public:
	virtual int payAmount() = 0;
};

class Game1 : public Game {
public:
	Game1() : Game() {}
	virtual int payAmount() {
		int n1 = cast();  //is-a ���� ������� Die Ŭ������ cast�� ����� �� ����.
		int n2 = cast();
		return n1+n2;
	}
};

class Game2 : public Game {
public:
	Game2() : Game() {}
	virtual int payAmount() {
		int n1 = cast();
		int n2 = cast();
		return abs(n1-n2);
	}
};


int main() {

	Game& g1 = Game1();
	std::cout << "Game1 = " << g1.payAmount() << std::endl;

	Game& g2 = Game2();
	std::cout << "Game2 = " << g2.payAmount() << std::endl;

	return 0;
}