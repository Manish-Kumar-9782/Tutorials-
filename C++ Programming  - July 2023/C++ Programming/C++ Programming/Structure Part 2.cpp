#include<iostream>
#include<string>
#include<limits>

using namespace std;

enum class BloodGroup {A_POSITIVE, A_NEGATIVE, B_POSITIVE, B_NEGATIVE, 
		AB_POSITIVE, AB_NEGATIVE, O_POSITIVE, O_NEGATIVE};


// public, private, protected

struct Student {
protected:
	string name;
	int age;
	double height;
	BloodGroup bloodgroup;

public:
	Student(string name, int age, double height, BloodGroup bloodgroup) {
		this->name = name;
		this->age = age;
		this->height = height;
		this->bloodgroup = bloodgroup;
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

		//cout << "Enter boodGroup: ";
		//cin >> bloodgroup;
	}

	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height: " << height << endl;
		//cout << "BloodGoroup: " << bloodgroup << endl;
	}
};

int main() {

	Student st("Kuldeep",20, 5.6, BloodGroup::B_POSITIVE);

	st.display();

	st.name;

	return 0;
}