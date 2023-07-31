#include<iostream>
#include<string>

using namespace std;

/*
	ostream& operator<<(ostream& first,obj& second){
	}
*/

struct Student {
	string name;
	int age;
	double height;
	string bloodGroup;
};


ostream& operator<<(ostream& COUT, Student& st) {

	COUT << "Student{"
		<< "Name:" << st.name << ", "
		<< "Age:" << st.age << ", "
		<< "Height:" << st.height << ", "
		<< "BloodGroup:" << st.bloodGroup 
		<< "}" << endl;

	return COUT;
}

istream& operator>>(istream& CIN, Student& st) {
	cout << "Name\t\tAge\tHeight\tBloodGroup" << endl;
	CIN >> st.name >> st.age >> st.height >> st.bloodGroup;
	return CIN;
}

int main() {

	// write or display data of Student variable by using the 
	// << output perator.
	Student st;

	cin >> st;
	cout << "\n----------------------------\n";
	cout << st;

	return 0;
}