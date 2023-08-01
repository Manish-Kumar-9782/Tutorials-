#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

typedef unsigned long long int  UL_int;

using ul_int = unsigned long long int;

const UL_int MAX_LEN = numeric_limits<streamsize>::max();

struct Student {
	string name;
	int age;
	float height;
	string bloodGroup;

	void tableDisplay() {
		cout << setw(15) << name
			<< setw(10) << age
			<< setw(10) << height
			<< setw(20) << bloodGroup << endl;
	}

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
		cin >> bloodGroup;
	}
};

void showHeader() {
	cout << setw(15) << "Name"
		<< setw(10) << "Age"
		<< setw(10) << "Height"
		<< setw(20) << "BloodGroup" << endl;
}

void sep() {
	cout << "\n==================================================================\n";
}

int main() {

	// Now we will create a new vector to hold the sutdents.
	vector<Student> students;

	char cmd = '\0';

	while (1) {

		showHeader();
		for (Student st : students) {
			st.tableDisplay();
		}

		sep();
		Student st;
		cout << "Do you want to Enter New Entry (y/n): ";
		cin >> cmd; 

		sep();
		if ((cmd == 'q') || (cmd == 'n')) {
			break;
		}

		if (cmd == 'y') {
			st.scan();
			students.push_back(st);
		}

		// to refresh the screen or clear the old content from the screen
		system("cls");
	}

	

	return 0;
}