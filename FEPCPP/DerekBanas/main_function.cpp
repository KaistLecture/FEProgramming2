#include <iostream>

using namespace std;

// ---------- FUNCTIONS ----------
// The function has return type, function name and attributes with 
// their data types
// The attribute data types must match the value passed in
// This data is passed by value
// You can define default values to attributes as long as they come last
// This is known as a function prototype
int addNumbers(int firstNum, int secondNum = 0) {

	int combinedValue = firstNum + secondNum;

	return combinedValue;

}

// An overloaded function has the same name, but different attributes
int addNumbers(int firstNum, int secondNum, int thirdNum) {

	return firstNum + secondNum + thirdNum;

}

// A recursive function is one that calls itself

int getFactorial(int number) {

	int sum;
	if (number == 1) sum = 1;
	else sum = (getFactorial(number - 1) * number);
	return sum;

	// getFactorial(2) [Returns 2] * 3
	// getFactorial(1) [Returns 1] * 2 <This value goes above>
	// 2 * 3 = 6

}

// Doesn't have a return type so use void
// Since I'm getting a pointer use int*
// Refer to the referenced variable with *age
void makeMeYoung(int* age) {

	cout << "I used to be " << *age << endl;
	*age = 21;

}

// A function that receives a reference can manipulate the value globally
void actYourAge(int& age) {

	age = 39;

}

// ---------- END OF FUNCTIONS ----------


int main() {


	// ---------- FUNCTIONS ----------
	// Functions allow you to reuse and better organize your code

	cout << addNumbers(1) << endl;

	// You can't access values created in functions (Out of Scope)
	// cout << combinedValue << endl;

	cout << addNumbers(1, 5, 6) << endl;

	cout << "The factorial of 3 is " << getFactorial(3) << endl;


	// ---------- POINTERS ----------
	// When data is stored it is stored in an appropriately sized box based
	// on its data type 

	int myAge = 39;
	char myGrade = 'A';

	cout << "Size of int " << sizeof(myAge) << endl;
	cout << "Size of char " << sizeof(myGrade) << endl;

	// You can reference the box (memory address) where data is stored with 
	// the & reference operator

	cout << "myAge is located at " << &myAge << endl;

	// A pointer can store a memory address
	// The data type must be the same as the data referenced and it is followed
	// by a *

	int* agePtr = &myAge;

	// You can access the memory address and the data 
	cout << "Address of pointer " << agePtr << endl;

	// * is the dereference or indirection operator
	cout << "Data at memory address " << *agePtr << endl;

	int badNums[5] = { 4, 13, 14, 24, 34 };
	int* numArrayPtr = badNums;

	// You can increment through an array using a pointer with ++ or --
	cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
	numArrayPtr++;
	cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;

	// An array name is just a pointer to the array
	cout << "Address " << badNums << " Value " << *badNums << endl;

	// When you pass a variable to a function you are passing the value
	// When you pass a pointer to a function you are passing a reference
	// that can be changed

	makeMeYoung(&myAge);

	cout << "I'm " << myAge << " years old now" << endl;

	// & denotes that ageRef will be a reference to the assigned variable
	int& ageRef = myAge;

	cout << "ageRef : " << ageRef << endl;

	// It can manipulate the other variables data
	ageRef++;

	cout << "myAge : " << myAge << endl;

	// You can pass the reference to a function
	actYourAge(ageRef);

	cout << "myAge : " << myAge << endl;

	return 0;
}