#include<iostream>
#include<string>

using namespace std;

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