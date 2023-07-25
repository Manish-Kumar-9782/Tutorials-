#include<iostream>
#include<string>

using namespace std;

struct Student {
	string name;
	int age;
	double height;
	string bloodGroup;
};

Student getStudent();
void displayStudent(Student st);

int main() {

	Student st = {};

	st = getStudent();
	cout << "\n====================\n";
	displayStudent(st);

	return 0;
}

Student getStudent() {
	Student st;

	cout << "Enter Name: ";
	//cin >> st.name;
	getline(cin, st.name);

	cin.ignore(100, '\n');

	cout << "Enter Age: ";
	cin >> st.age;

	cout << "Enter Height: ";
	cin >> st.height;

	cout << "Enter boodGroup: ";
	cin >> st.bloodGroup;

	return st;
}

void displayStudent(Student st) {

	cout << "Name: " << st.name << endl;
	cout << "Age: " << st.age << endl;
	cout << "Height: " << st.height << endl;
	cout << "BloodGoroup: " << st.bloodGroup << endl;

}