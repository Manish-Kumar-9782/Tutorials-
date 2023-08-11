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

struct Address {
	int plotNo;
	int streeNo;
	string address_line;
	string landmark;
	string city;
	int pincode;
};


class Student {
private:
	string name;
	int age;
	double height;
	string bloodGroup;
	Address *address;

public:
	// default constructor
	Student() {
		cout << "default constructor called." << endl;
		this->name = "";
		this->age = 0;
		this->height = 0;
		this->bloodGroup = "";
	}

	// parameterized constructor
	Student(string name, int age, double height, string bloodGroup) {
		this->name = name;
		this->age = age;
		this->height = height;
		this->bloodGroup = bloodGroup;
		cout << "parameterized constructor called" << endl;
	}

	// copy constructor (shallow copy)
	Student(Student &st, const int deep = 0) {
		// copy constructor called
		cout << "copy constructor invoked" << endl;
		this->name = st.name;
		this->age = st.age;
		this->height = st.height;
		this->bloodGroup = st.bloodGroup;
		// Note here this->address is pointer and it hold only address(reference) of the Address type
		// variable.
		
		if (deep) {
			this->address = new Address(); //  allocating new student a new address object/variable
			*this->address = *st.address;  // copying each value of st.address referred object to
			// newly created address object
		}
		else {
			this->address = st.address;  // here we are only copying the reference of the object
		}
		

	}

	void set_address(string city, string line) {
		cout << "setting the address " << endl;

		this->address = new Address();

		this->address->address_line = line;
		this->address->city = city;
		cout << "setting the address completed.. " << endl;
	}

	void update_address(string city, string line) {
		this->address->city = city;
		this->address->address_line = line;
	}

	void set_info(string name = "", int age = 0, double height = 0, string bloodGroup = "") {
		if (name != "") this->name = name;
		if (age != 0) this->age = age;
		if (height != 0) this->height = height;
		if (bloodGroup != "") this->bloodGroup = bloodGroup;
	}

	void display_info() {
		cout << "Name: " << this->name << endl
			<< "Age: " << this->age << endl
			<< "Height: " << this->height << endl
			<< "BloodGroup: " << this->bloodGroup << endl
			<< "Address: " << this->address->address_line << ", " << this->address->city << endl;
	}
};


int main() {

	// first object with default constructor
	Student st;

	st.set_info("manish", 21, 5.6, "B+");
	st.set_address("Jaipur", "faltu bangla road");
		
	Student st2(st,1);  // copy constructor.



	st.display_info();
	cout << "\n\n===================================" << endl;
	st2.display_info();

	st2.update_address("Jodhpur", "Jodhpur Railway station cololy");
	st2.display_info();
	cout << "\n\n===================================" << endl;
	st.display_info();

	cin.get();
}