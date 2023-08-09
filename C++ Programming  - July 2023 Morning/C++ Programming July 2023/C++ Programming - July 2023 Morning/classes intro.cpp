#include<iostream>
#include<string>


// access modifiers.

using namespace std;

class Student{
private:
	string name;
	int age;
	double height;
	string bloodGroup;

public:
	// constructor if parameter list is blank then it is called default constructor
	Student() {
		this->name = "";
		this->age = 0;
		this->height = 0;
		this->bloodGroup = "";
		cout << "default constructor invoked..." << endl;
	}

	// overloading constructor, parameterized constructor
	Student(string name, int age, double height, string bloodGroup) {
		this->name = name;
		this->age = age;
		this->height = height;
		this->bloodGroup = bloodGroup;
		cout << "parameterized constructor invoked..." << endl;
	}

	void display_info() {
		cout << "Name: " << this->name << endl;
	}

	void set_age(int age) {
		// here is the validation
		if (age <= 90 && age >= 18) {
			this->age = age;
		}
		else {
			cout << "age is not valid..., it must be in range of (18, 90)." << endl;
		}
	}
};

int main() {

	Student st1("Kush",21,5.6, "B+");

	st1.display_info();
	st1.set_age(16);

	return 0;
}