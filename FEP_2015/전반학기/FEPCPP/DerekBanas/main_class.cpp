#include <iostream>
#include <string>

using namespace std;

// ---------- CLASSES ----------
// classes start with the name class

class Animal
{

	// private variables are only available to methods in the class
private:
	int height;
	int weight;
	string name;

	// A static variable shares the same value with every object in the class
	static int numOfAnimals;

	// Public variables can be accessed by anything with access to the object
public:
	int getHeight() { return height; }
	int getWeight() { return weight; }
	string getName() { return name; }
	void setHeight(int cm) { height = cm; }
	void setWeight(int kg) { weight = kg; }
	void setName(string dogName) { name = dogName; }

	// Declared as a prototype
	void setAll(int, int, string);

	// Declare the constructor
	Animal(int, int, string);

	// Declare the deconstructor
	~Animal();

	// An overloaded constructor called when no data is passed
	Animal();

	// protected members are available to members of the same class and 
	// sub classes

	// Static methods aren't attached to an object and can only access
	// static member variables
	static int getNumOfAnimals() { return numOfAnimals; }

	// This method will be overwritten in Dog
	void toString();

};

int Animal::numOfAnimals = 0;

// Define the protoype method setAll
void Animal::setAll(int height, int weight, string name) {

	// This is used to refer to an object created of this class type
	this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;

}

// A constructor is called when an object is created
Animal::Animal(int height, int weight, string name) {

	this->height = height;
	this->weight = weight;
	this->name = name;

}

// The destructor is called when an object is destroyed
Animal::~Animal() {

	cout << "Animal " << this->name << " destroyed" << endl;

}

// A constructor called when no attributes are passed
Animal::Animal() {
	numOfAnimals++;
}

// This method prints object info to screen and will be overwritten
void Animal::toString() {

	cout << this->name << " is " << this->height << " cms tall and "
		<< this->weight << " kgs in weight" << endl;

}

// We can inherit the variables and methods of other classes
class Dog : public Animal {

private:
	string sound = "Woof";
public:
	void getSound() { cout << sound << endl; }

	// Declare the constructor
	Dog(int, int, string, string);

	// Declare the default constructor and call the default superclass
	// constructor
	Dog() : Animal() {};

	// Overwrite toString
	void toString();

};

// Dog constructor passes the right attributes to the superclass
// constructor and then handles the attribute bark that remains
Dog::Dog(int height, int weight, string name, string bark) :
	Animal(height, weight, name) {

	this->sound = bark;

}

// toString method overwritten
void Dog::toString() {

	// Because the attributes were private in Animal they must be retrieved 
	// by called the get methods
	cout << this->getName() << " is " << this->getHeight() <<
		" cms tall and " << this->getWeight() << " kgs in weight and says " <<
		this->sound << endl;

}

// ---------- END OF CLASSES ----------




int main() {
	// ---------- CLASSES & OBJECTS ----------
	// Classes are the blueprints for modeling real world objects
	// Real world objects have attributes, classes have members / variables
	// Real world objects have abilities, classes have methods / functions
	// Classes believe in hiding data (encapsulation) from outside code

	// Declare a Animal type object
	Animal fred;

	// Set the values for the Animal
	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");

	// Get the values for the Animal
	cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
		<< fred.getWeight() << " kgs in weight" << endl;

	fred.setAll(34, 12, "Fred");

	cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
		<< fred.getWeight() << " kgs in weight" << endl;

	// Creating an object using the constructor
	Animal tom(36, 15, "Tom");

	cout << tom.getName() << " is " << tom.getHeight() << " cms tall and "
		<< tom.getWeight() << " kgs in weight" << endl;

	// Demonstrate the inheriting class Dog
	Dog spot(38, 16, "Spot", "Woof");

	// static methods are called by using the class name and the scope operator
	cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;

	spot.getSound();

	// Test the toString method that will be overwritten
	tom.toString();
	spot.toString();

	// We can call the superclass version of a method with the class name 
	// and the scope operator
	spot.Animal::toString();

	// When a function finishes it must return an integer value
	// Zero means that the function ended with success
	return 0;
}