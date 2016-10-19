#include <iostream>
#include <string>

class Person {  //�߻�Ŭ���� (abstract class)
protected:
	std::string name;
	int age;
public:
	Person(std::string age, int name) :
		name(age), age(name) {}
	virtual void print() = 0; //���������Լ� (pure virtual function)
protected:
	void printPerson() {
		std::cout << "name=" << name << std::endl;
		std::cout << "age=" << age << std::endl;
		std::cout << "------------------" << std::endl;
	}
};

//Person Ŭ�������� ��ӹ��� subclass
class Student : public Person {
public:
	Student(std::string name, int age, int year)
		: Person(name, age), year(year) {}
	virtual void print() { 
		//function override (�Լ��������̵�: subclass���� superclass�� ����Լ��� ������)
		Person::printPerson(); //superclass�� �Լ��� ȣ��
		std::cout << "year = " << year << std::endl;
		std::cout << "------------------" << std::endl;
	}
protected:
	int year;
};


class Professor : public Person {
public:	
	enum Position { Lecturer = 1, Prof = 2 };
	Professor(std::string n, int a, Position p)
		: Person(n, a), position_(p) {}
	virtual void print()  {
		Person::printPerson();
		if (position_==Lecturer) 
			std::cout << "position = Lecturer" << std::endl;
		else 
			std::cout << "position = Prof." << std::endl;
		std::cout << "------------------" << std::endl;
	}
protected:
	Position position_;
};

void printProfile(Person& p) {
	p.print();
}

int main() {
	//Person a("A", 30);
	//a.print();

	Student b("B", 24, 3);
	b.print();

	Professor c("C", 50, Professor::Lecturer);
	c.print();

	Student d("D", 30, 4);
	printProfile(d);

	Professor e("E", 60, Professor::Prof);
	printProfile(e);
	return 0;
}