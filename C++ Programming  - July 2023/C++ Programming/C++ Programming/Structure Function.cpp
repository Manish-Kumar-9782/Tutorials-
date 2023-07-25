#include<iostream>
#include<string>

using namespace std;

struct Student {
	string name;
	int age;
	double height;
	string bloodGroup;

	void init(string name, int age, double height, string bloodGroup) {
		this->name = name;
		this->age = age;
		this->height = height;
		this->bloodGroup = bloodGroup;
	}

	void scan() {
		cout << "Enter Name: ";
		//cin >> st.name;
		getline(cin, name);

		cin.ignore(100, '\n');

		cout << "Enter Age: ";
		cin >> age;

		cout << "Enter Height: ";
		cin >> height;

		cout << "Enter boodGroup: ";
		cin >> bloodGroup;
	}

	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height: " << height << endl;
		cout << "BloodGoroup: " << bloodGroup << endl;
	}
};

Student getStudent();
void displayStudent(Student st);

int main() {

	Student st = {};

	

	//st.scan();
	st.init("Abishek Singh", 21, 5.8, "A-");
	cout << "\n====================\n";
	st.display();

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