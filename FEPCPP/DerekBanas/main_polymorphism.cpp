#include <iostream>
using namespace std;

// Virtual Methods and Polymorphism
// Polymorpism allows you to treat subclasses as their superclass and yet
// call the correct overwritten methods in the subclass automatically

class Animal{
public:
	void getFamily() { cout << "We are Animals" << endl; }

	// When we define a method as virtual we know that Animal
	// will be a base class that may have this method overwritten
	void getClass() { cout << "I'm an Animal" << endl; }
};

class Dog : public Animal{
public:
	void getClass() { cout << "I'm a Dog" << endl; }

};

class GermanShepard : public Dog{
public:
	void getClass() { cout << "I'm a German Shepard" << endl; }
	void getDerived() { cout << "I'm an Animal and Dog" << endl; }

};

void whatClassAreYou(Animal *animal){
	animal->getClass();
}

int main(){

	Animal *animal = new Animal;
	Dog *dog = new Dog;

	// If a method is marked virtual or not doesn't matter if we call the method
	// directly from the object
	animal->getClass();
	dog->getClass();

	// If getClass is not marked as virtual outside functions won't look for 
	// overwritten methods in subclasses however
	whatClassAreYou(animal);
	whatClassAreYou(dog);

	Dog spot;
	GermanShepard max;

	// A base class can call derived class methods as long as they exist 
	// in the base class
	Animal* ptrDog = &spot;
	Animal* ptrGShepard = &max;

	// Call the method not overwritten in the super class Animal
	ptrDog->getFamily();

	// Since getClass was overwritten in Dog call the Dog version
	ptrDog->getClass();

	// Call to the super class
	ptrGShepard->getFamily();

	// Call to the overwritten GermanShepard version
	ptrGShepard->getClass();

	return 0;
}