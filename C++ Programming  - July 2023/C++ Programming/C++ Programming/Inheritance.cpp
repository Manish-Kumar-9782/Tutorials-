#include<iostream>
#include<string>

using namespace std;

// base class or super class or parent class
class Person {
	// by default we have access modifier private
private:
	string name;
	int age;
	double height;

public:

	Person() {

	}

	Person(string name, int age, double height) {
		cout << "initialized the Person data members " << endl;
		this->name = name;
		this->age = age;
		this->height = height;
	}
	
	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	int getAge() {
		return this->age;
	}

	double getHeight() {
		return this->height;
	}
};


// subclass or child class
class Student : public Person {
	// inheriting the Person by public mode
private:
	int rollNo;

public:
	// constructor of the sub class
	Student(string name, int age, double height, int rollNo): Person(name, age, height) {
		cout << "initialized the Student data members..." << endl;
		this->rollNo = rollNo;
	}

	void display_info() {
		cout << "RollNo: " <<this->rollNo<< endl;

		// Not we can't access private data members directly, for that we need getter or setter method.
		cout << "Name: " <<this->getName()<<endl;
		cout << "Age: " << this->getAge() << endl;
		cout << "Height: " << this->getHeight() << endl;
	}
};


int main() {

	Student st("kuldeep",20, 5.6, 1007);

	st.display_info();

}