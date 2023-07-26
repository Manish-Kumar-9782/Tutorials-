#include<iostream>
#include<string>
#include<limits>

using namespace std;

typedef unsigned long long int  UL_int;

const UL_int MAX_LEN = numeric_limits<streamsize>::max();

struct Student {
	string name;
	int age;
	double height;
	string bloodgroup;
};

int main() {

	Student st = {};

	cout << "Student Age: ";
	cin >> st.age;

	cin.ignore();
	
	cout << "Enter Student name: ";
	getline(cin, st.name);

	cin.ignore(100, '\n');
	cout << "Enter Student height: ";
	cin >> st.height;

	cout << "Enter Student BloodGroup: ";
	cin >> st.bloodgroup;

	cout << "Student Name: " << st.name << endl;
	cout << "Student Age: " << st.age << endl;
	cout << "Student Height: " << st.height << endl;
	cout << "Student BloodGroup: " << st.bloodgroup << endl;
}