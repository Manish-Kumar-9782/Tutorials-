#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

struct Student {
	string name;
	int age;
	float height;
	string bloodGroup;

	void scan() {

		cin.ignore(100, '\n');

		cout << "Enter Name: ";
		getline(cin, name);

		cin.ignore(100, '\n');

		cout << "Enter Age: ";
		cin >> age;

		cout << "Enter Height: ";
		cin >> height;

		cin.ignore(100, '\n');
		cout << "Enter BloodGroup: ";
		getline(cin, bloodGroup);
	}

	void tableDisplay() {
		cout << setw(20) << name
			<< setw(10) << age
			<< setw(10) << height
			<< setw(15) << bloodGroup
			<< endl;
	}
};

void showHeader() {
	cout << setw(20) << "Name"
		<< setw(10) << "Age"
		<< setw(10) << "Height"
		<< setw(15) << "BloodGroup"
		<< endl;
}

void sep() {
	cout << "\n=========================================================\n";
}

int main() {

	

	vector<Student> students;

	while (1) {

		// first we will show the current data form students vector.
		showHeader();
		for (Student st : students) {
			st.tableDisplay();
		}
		sep();

		// asking to user for new student entry
		char cmd='\0';
		cout << "Do you want to insert a new student (y/n): ";
		cin >> cmd;
		sep();

		// if n/no or q/quit is given then we will brak the loop.
		if ((cmd == 'n') || (cmd == 'q')) {
			break;
		}

		// if y/yes then we will create a new student then scan it.
		// after scanning we will add it to the students vector.
		if (cmd == 'y') {
			Student st;
			st.scan();
			students.push_back(st);
		}

		// after new entry we will clear the screen
		system("cls");
	}

	return 0;
}