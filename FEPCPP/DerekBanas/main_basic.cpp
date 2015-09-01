// This is a comment
/*
* Multi-line comment
*/

// Tells the compiler iostream library which contains the function cout
#include <iostream>
// Allows us to use vectors
#include <vector>
#include <algorithm>
#include <valarray>
// Allows us to use strings
#include <string>

// Allows functions in the std namespace to be used without their prefix
// std::cout becomes cout
using namespace std;

void showVector(int n) {
	std::cout << n << "\t";
}

// This is where execution begins. Attributes can be sent to main
int main() {

#define _chapter1_

#ifdef _chapter1_

	// Chapter 1. 자료형, 연산
	// cout outputs text and a carriage return with endl
	// Statements must end with a semicolon
	// Strings must be surrounded by "
	// << sends the text via standard output to the screen
	cout << "Hello World" << endl;

	// ---------- VARIABLES / DATA TYPES ----------
	// Variables start with a letter and can contain letters, numbers and _
	// They are case sensitive

	// A value that won't change is a constant
	// Starts with const and it should be uppercase
	const double PI = 3.1415926535;

	// chars can contain 1 character that are surrounded with ' and is one byte in size
	char myGrade = 'A';

	// bools have the value of (true/1) or (false/0)
	bool isHappy = true;

	// ints are whole numbers
	int myAge = 39;

	// floats are floating point numbers accurate to about 6 decimals
	float favNum = 3.141592;

	// doubles are floating point numbers accurate to about 15 digits
	double otherFavNum = 1.6180339887;

	auto autoVar1 = 'c';
	auto autoVar2 = 1.23;

	// You can output a variable value like this
	cout << "Favorite Number " << favNum << endl;

	// You can get the number of bytes for a data type with sizeof
	cout << "Size of int " << sizeof(myAge) << endl;
	cout << "Size of char " << sizeof(myGrade) << endl;
	cout << "Size of bool " << sizeof(isHappy) << endl;
	cout << "Size of float " << sizeof(favNum) << endl;
	cout << "Size of double " << sizeof(otherFavNum) << endl;
	cout << "Size of auto1 " << sizeof(autoVar1) << endl;
	cout << "Size of auto2 " << sizeof(autoVar2) << endl;

	int largestInt = 2147483647;
	cout << "Largest int " << largestInt << endl;
	cout << largestInt + 1 << endl;

	// ---------- ARITHMETIC ----------
	// The arithmetic operators are +, -, *, /, %, ++, --

	cout << "5 + 2 = " << 5 + 2 << endl;
	cout << "5 - 2 = " << 5 - 2 << endl;
	cout << "5 * 2 = " << 5 * 2 << endl;
	cout << "5 / 2 = " << 5 / 2 << endl;
	cout << "5 / 2.0 = " << 5 / 2.0 << endl;
	cout << "5 % 2 = " << 5 % 2 << endl;

	int five = 5;
	cout << "5++ = " << five++ << endl;
	cout << "++5 = " << ++five << endl;
	cout << "5-- = " << five-- << endl;
	cout << "--5 = " << --five << endl;

	// Shorthand assignment operators
	// a += b == a = a + b
	// There is also -=, *=, /=, %=

	// Order of Operation states * and / is performed before + and -

	cout << "1 + 2 - 3 * 2 = " << 1 + 2 - 3 * 2 << endl;
	cout << "(1 + 2 - 3) * 2 = " << (1 + 2 - 3) * 2 << endl;

	// ---------- CASTING ----------
	// You convert from one data type to another by casting
	// char, int, float, double

	cout << "4 / 5 = " << 4 / 5 << endl;
	cout << "4 / 5 = " << (float)4 / 5 << endl;

#endif

#ifdef _chapter2_
//Chapter 2. 제어문
// ---------- IF STATEMENT ----------
// Executes different code depending upon a condition

// Comparison operators include ==, !=, >, <, >=, <=
// Will return true (1) if the comparison is true, or false (0)

// Logical operators include &&, ||, !
// Used to test 2 or more conditionals

int age = 70;
int ageAtLastExam = 16;
bool isNotIntoxicated = true;

if ((age >= 1) && (age < 16)) {
	cout << "You can't drive" << endl;
}
else if (!isNotIntoxicated) {
	cout << "You can't drive" << endl;
}
else if (age >= 80 && ((age > 100) || ((age - ageAtLastExam) > 5))) {
	cout << "You can't drive" << endl;
}
else {
	cout << "You can drive" << endl;
}

// ---------- SWITCH STATEMENT ----------
// switch is used when you have a limited number of possible options

int greetingOption = 2;

switch (greetingOption) {

case 1:
	cout << "bonjour" << endl;
	break;

case 2:
	cout << "Hola" << endl;
	break;

case 3:
	cout << "Hallo" << endl;
	break;

default:
	cout << "Hello" << endl;
}

// ---------- TERNARY OPERATOR ----------
// Performs an assignment based on a condition
// variable = (condition) ? if true : if false

int largestNum = (5 > 2) ? 5 : 2;

cout << "The biggest number is " << largestNum << endl;

#endif

#ifdef _chapter3_
//Chapter3. 배열, 반복문
// ---------- ARRAYS ----------
// Arrays store multiple values of the same type

// You must provide a data type and the size of the array
int myFavNums[5];

// You can declare and add values in one step
int badNums[5] = { 4, 13, 14, 24, 34 };

// The first item in the array has the label (index) of 0
cout << "Bad Number 1: " << badNums[0] << endl;

// You can create multidimensional arrays
char myName[5][5] = { { 'D', 'e', 'r', 'e', 'k' },{ 'B', 'a', 'n', 'a', 's' } };

cout << "2nd Letter in 2nd Array: " << myName[1][1] << endl;

// You can change a value in an array using its index
myName[0][2] = 'e';

cout << "New Value " << myName[0][2] << endl;

// ---------- FOR LOOP ----------
// Continues to execute code as long as a condition is true

for (int i = 1; i <= 10; i++) {

	cout << i << endl;

}

// You can also cycle through an array by nesting for loops
for (int j = 0; j < 5; j++) {

	for (int k = 0; k < 5; k++) {
		cout << myName[j][k];
	}

	cout << endl;

}

// ---------- WHILE LOOP ----------
// Use a while loop when you don't know ahead of time when a loop will end

// Generate a random number between 1 and 100
int randNum = (rand() % 100) + 1;

while (randNum != 100) {

	cout << randNum << ", ";

	// Used to get you out of the loop
	randNum = (rand() % 100) + 1;

}

cout << endl;

// You can do the same as the for loop like this
// Create an index to iterate out side the while loop
int index = 1;

while (index <= 10) {

	cout << index << endl;

	// Increment inside the loop
	index++;

}

// ---------- DO WHILE LOOP ----------
// Used when you want to execute what is in the loop at least once

// Used to store a series of characters
string numberGuessed;
int intNumberGuessed = 0;

do {
	cout << "Guess between 1 and 10: ";

	// Allows for user input
	// Pass the source and destination of the input
	getline(cin, numberGuessed);

	// stoi converts the string into an integer
	intNumberGuessed = stoi(numberGuessed);
	cout << intNumberGuessed << endl;

	// We'll continue looping until the number entered is 4
} while (intNumberGuessed != 4);

cout << "You Win" << endl;

#endif

#ifdef _chapter4_
//Chapter4. 스트링
// ---------- STRINGS ----------
// The string library class provides a string object
// You must always surround strings with "
// Unlike the char arrays in c, the string object automatically resizes

// The C way of making a string
char happyArray[6] = { 'H', 'a', 'p', 'p', 'y', '\0' };

// The C++ way
string birthdayString = " Birthday";

// You can combine / concatenate strings with +
cout << happyArray + birthdayString << endl;

string yourName;
cout << "What is your name? ";
getline(cin, yourName);

cout << "Hello " << yourName << endl;

double eulersConstant = .57;
string eulerGuess;
double eulerGuessDouble;
cout << "What is Euler's Constant? ";
getline(cin, eulerGuess);

// Converts a string into a double
// stof() for floats
eulerGuessDouble = stod(eulerGuess);

if (eulerGuessDouble == eulersConstant) {

	cout << "You are right" << endl;

}
else {

	cout << "You are wrong" << endl;

}

// Size returns the number of characters
cout << "Size of string " << eulerGuess.size() << endl;

// empty tells you if string is empty or not
cout << "Is string empty " << eulerGuess.empty() << endl;

// append adds strings together
cout << eulerGuess.append(" was your guess") << endl;

string dogString = "dog";
string catString = "cat";

// Compare returns a 0 for a match, 1 if less than, -1 if greater then
cout << dogString.compare(catString) << endl;
cout << dogString.compare(dogString) << endl;
cout << catString.compare(dogString) << endl;

// assign copies a value to another string 
string wholeName = yourName.assign(yourName);
cout << wholeName << endl;

// You can get a substring as well by defining the starting index and the
// number of characters to copy
string firstName = wholeName.assign(wholeName, 0, 5);
cout << firstName << endl;

// find returns the index for the string your searching for starting
// from the index defined
int lastNameIndex = yourName.find("Banas", 0);
cout << "Index for last name " << lastNameIndex << endl;

// insert places a string in the index defined
yourName.insert(0, "Justin ");
cout << yourName << endl;

// erase will delete 6 characters starting at index 7
yourName.erase(6, 7);
cout << yourName << endl;

// replace 5 characters starting at index 6 with the string Maximus
yourName.replace(6, 1, "Maximus");
cout << yourName << endl;

#endif

#ifdef _chapter5_
//Chapter5. STL: 벡터
// ---------- VECTORS ----------
// Vectors are like arrays, but their size can change


int lotteryNumArray[5] = { 4, 13, 14, 24, 34 };
vector <int> lotteryNumVect(lotteryNumArray, lotteryNumArray+5);
cout << "Size of vector = " << lotteryNumVect.size() << endl;
for_each(lotteryNumVect.begin(), lotteryNumVect.end(), showVector);
cout << endl;

// Add the array to the vector starting at the beginning of the vector
lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray + 3);
cout << "Size of vector = " << lotteryNumVect.size() << endl;
for_each(lotteryNumVect.begin(), lotteryNumVect.end(), showVector);
cout << endl;

// Insert a value into the 5th index
lotteryNumVect.insert(lotteryNumVect.begin() + 5, 44);
for_each(lotteryNumVect.begin(), lotteryNumVect.end(), showVector);
cout << endl;

// push_back adds a value at the end of a vector
lotteryNumVect.push_back(64);

// back gets the value in the final index
cout << "Final Value = " << lotteryNumVect.back() << endl;
for_each(lotteryNumVect.begin(), lotteryNumVect.end(), showVector);
cout << endl;

// pop_back removes the final element
lotteryNumVect.pop_back();

// front returns the first element
cout << "First Element = " << lotteryNumVect.front() << endl;

// back returns the last element
cout << "Last Element = " << lotteryNumVect.back() << endl;

// empty tells you if the vector is empty
cout << "Vector Empty = " << lotteryNumVect.empty() << endl;
lotteryNumVect.resize(0);
cout << "Vector Empty = " << lotteryNumVect.empty() << endl;

//valarray
double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
valarray<double> v1; // an array of int, size 0
valarray<int> v2(8); // an array of 8 int elements
valarray<int> v3(10, 8); // an array of 8 int elements, // each set to 10
valarray<double> v4(gpa, 4); // an array of 4 elements  // initialized to the first 4 elements of gpa
for (int i = 0; i < v4.size(); ++i)
	cout << v4[i] << "\t";
cout << endl;

valarray<double> v5 = v4 * 2.;
valarray<double> v6 = v4 + v5;
valarray<double> v7 = v4.apply(exp);
for (int i = 0; i < v7.size(); ++i)
	cout << v7[i] << "\t";
cout << endl;


cout << "Max = " << v7.max() << endl;
cout << "Min = " << v7.min() << endl;
cout << "Sum = " << v7.sum() << endl;


#endif

#ifdef _chapter6_
//Chapter6. 예외처리
// ---------- EXCEPTION HANDLING ----------
// You can be prepared for potential problems with exception handling

int number = 1;

try {

	if (number != 0) {
		cout << 2 / number << endl;
	}
	else throw(number);

}
catch (int number) {

	cout << number << " is not valid input" << endl;

}

#endif



	return 0;

}

