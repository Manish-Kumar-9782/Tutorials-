#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

/*
	Access modifiers: 
		Private
		Public
		Protected
*/
class Student {
private:
	string name;
	int age;
	double height;
	string bloodGroup;

public:
	// Constructor
	Student() {
		cout << "default constructor called."<<endl;
		this->name = "";
		this->age = 0;
		this->height = 0;
		this->bloodGroup = "";
	}

	Student(string name, int age, double height, string bloodGroup) {
		this->name = name;
		this->age = age;
		this->height = height;
		this->bloodGroup = bloodGroup;
		cout << "parameterized constructor called" << endl;
	}

	void set_info(string name="", int age=0, double height=0, string bloodGroup="") {
		if(name != "") this->name = name;
		if(age != 0) this->age = age;
		if(height !=0 ) this->height = height;
		if(bloodGroup != "") this->bloodGroup = bloodGroup;
	}

	void display_info() {
		cout << "Name: " << this->name << endl
			<< "Age: " << this->age << endl
			<< "Height: " << this->height << endl
			<< "BloodGroup: " << this->bloodGroup << endl;
	}
};


int main() {

	// first object with default constructor
	Student st;

	st.set_info("manish");
	//Student st2("kuldeep", 21, 5.6, "B+");


	st.display_info();
	cin.get();
}