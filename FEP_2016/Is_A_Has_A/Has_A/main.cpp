#include <iostream>
#include <random>
#include <cmath>
#include <chrono>

class Die {  //Is-A 관계에서와 동일함
public:
	int cast() {
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::mt19937 gen(seed);
		std::uniform_int_distribution<int> engine(1, 6);
		return engine(gen);
	}
};

class Game {  
public:
	Game() : d(Die()) {}
	virtual int payAmount() = 0;
protected:
	Die d;    //Has-A 관계는 Die에서 상속받는게 아니고 Die의 객체를 멤버변수로 소유함
};

class Game1 : public Game {
public:
	Game1() : Game() {}
	virtual int payAmount() {
		int n1 = d.cast();  //has-a 관계로 소유한 Die의 객체 d를 이용해 cast 호출
		int n2 = d.cast();
		return n1 + n2;
	}
};

class Game2 : public Game {
public:
	Game2() : Game() {}
	virtual int payAmount() {
		int n1 = d.cast();
		int n2 = d.cast();
		return abs(n1 - n2);
	}
};


int main() {

	Game& g1 = Game1();
	std::cout << "Game1 = " << g1.payAmount() << std::endl;

	Game& g2 = Game2();
	std::cout << "Game2 = " << g2.payAmount() << std::endl;

	return 0;
}