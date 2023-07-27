#include<iostream>
#include<string>
#include<limits>

using namespace std;

using UL_int = unsigned long long int;

const UL_int MAX_STREAM_LEN = numeric_limits<streamsize>::max();


/*
// syntax for output operator << :
	
	ostream& operator<<(ostream& COUT, Student& st){
		COUT << st.name;
		COUT << st.age;
		COUT << st.height;
		COUT << st.bloodGroup;
	}

*/


struct Student {
	string name;
	int age;
	double height;
	string bloodgroup;
};


ostream& operator<<(ostream& COUT, Student& st) {
		
	COUT << "Student< " << st.name << "," << st.age << "," << st.height << "," << st.bloodgroup << " >" << endl;

	return COUT;

}

istream& operator>>(istream& CIN, Student& st) {

	cout << "Name\tAge\tHeight\tBloodGroup"<<endl;
	CIN >> st.name >> st.age >> st.height >> st.bloodgroup;

	return CIN;
}

int main() {

	Student st;

	cin >> st;

	cout << st;


	return 0;
}