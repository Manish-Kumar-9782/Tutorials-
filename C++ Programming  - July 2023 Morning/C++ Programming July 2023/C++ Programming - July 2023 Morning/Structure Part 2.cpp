#include<iostream>
#include<string>
#include<limits>

using namespace std;

typedef unsigned long long int  UL_int;

using ul_int = unsigned long long int;

const UL_int MAX_LEN = numeric_limits<streamsize>::max();

struct Student {
	string name;
	int age;
	double height;
	string bloodgroup;

	void scan() {
		// first we will flush the current stream

		cin.ignore(MAX_LEN, '\n');

		cout << "Enter Student Name: ";
		getline(cin, name);
		cin.ignore(MAX_LEN, '\n');
		// Now again flushing the stream after taking the name

		cout << "Enter Student Age: ";
		cin >> age;

		cout << "Enter Student Height: ";
		cin >> height;

		cout << "Enter Student BloodGroup: ";
		cin >> bloodgroup;
	}

	void display() {

		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height: " << height << endl;
		cout << "BloodGroup: " << bloodgroup << endl;
	}
};

void separator() {
	cout << "\n=====================================\n";
}

void main() {
	Student st,st2;

	st.scan();
	separator();
	st2.scan();

	
	separator();
	separator();

	st.display();
	separator();
	st2.display();
}