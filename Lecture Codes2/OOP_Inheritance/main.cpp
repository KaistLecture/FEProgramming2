#include <iostream>
#include <string>

class Person {
protected:
	std::string name;
	int age;
public:
	Person(std::string age, int name) :
		name(age), age(name) {}
	void print() {
		std::cout << "name=" << name << std::endl;
		std::cout << "age=" << age << std::endl;
		std::cout << "------------------" << std::endl;
	}
};
class Student : public Person {
public:
	Student(std::string name, int age, int year)
		: Person(name, age), year(year) {}
	void print() {
		Person::print();
		std::cout << "year = " << year << std::endl;
		std::cout << "------------------" << std::endl;
	}
protected:
	int year;
};

int main() {
	Person a("A", 30);
	a.print();

	Student b("B", 24, 3);
	b.print();
	return 0;
}