#include <iostream>
using namespace std;

// Polymorpism allows you to treat subclasses as their superclass and yet
// call the correct overwritten methods in the subclass automatically

class Animal{
public:
	virtual void makeSound(){ cout << "The Animal says grrrr" << endl; }

	// The Animal class could be a capability class that exists
	// only to be derived from by containing only virtual methods
	// that do nothing

};

class Cat : public Animal{
public:
	void makeSound(){ cout << "The Cat says meow" << endl; }
};

class Dog : public Animal{
public:
	void makeSound(){ cout << "The Dog says woof" << endl; }
};

// An abstract data type is a class that acts as the base to other classes
// They stand out because its methods are initialized with zero
// A pure virtual method must be overwritten by subclasses

class Car{
public:
	virtual int getNumWheels() = 0;
	virtual int getNumDoors() = 0;
};

class StationWagon : public Car{
public:
	int getNumWheels() { return 4; }
	int getNumDoors() { return 4; }
	StationWagon() { }
	~StationWagon();
};

int main(){

	Animal* pCat = new Cat;
	Animal* pDog = new Dog;

	pCat->makeSound();
	pDog->makeSound();

	// Create a StationWagon using the abstract data type Car
	Car* stationWagon = new StationWagon();

	cout << stationWagon->getNumWheels() << endl;

	delete pCat;
	delete pDog;
	delete stationWagon;

	return 0;
}