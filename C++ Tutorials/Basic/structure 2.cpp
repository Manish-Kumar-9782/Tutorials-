#include <iostream>
#include <string>

using namespace std;

// In this section we don't have to use the typedef to make an alias name
// to short our structure data type.

// we can directly make variable by using the Student identifier.

struct Student
{
	string name;
	int age;
	float height;

	void get_details()
	{

		cout << "Enter your name: ";
		cin >> name;

		cout << "Enter your age: ";
		cin >> age;

		cout << "Enter your height: ";
		cin >> height;
	}

	void show_details()
	{

		cout << "Your Name: " << name << endl;
		cout << "Your age: " << age << endl;
		cout << "Your height:" << height << endl;
	}
};

int add(int a, int b)
{

	cout << "adding integers function...\n\n";
	return a + b;
}

string add(string a, string b)
{
	cout << "adding strings function...\n\n";
	return a + b;
}

int main()
{

	Student st, st2;

	st.get_details();
	
	
	
//	st2.get_details();
	cout << "Your details:" << endl;
	
//	cin >> ws; // clearing the buffer
//	cin.sync();
	cout << endl<<"cin buffer :" <<cin.get() <<endl;
	
	st.show_details();
//	st2.show_details();

//	cout << "adding integers:\t" << add(10, 20) << endl;
//	cout << "adding strings:\t" << add("hello ", "Welcome") << endl;

	// ios_base::

	return 0;
}
