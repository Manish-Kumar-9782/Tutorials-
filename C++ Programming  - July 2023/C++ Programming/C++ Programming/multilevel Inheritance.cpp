#include<iostream>
#include<string>


using namespace std;

// base class or super class or parent class
class Person {
	// by default we have access modifier private
private:
	string name;
	int age;
	double height;

public:

	Person() {

	}

	Person(string name, int age, double height) {
		cout << "initialized the Person data members " << endl;
		this->name = name;
		this->age = age;
		this->height = height;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	int getAge() {
		return this->age;
	}

	double getHeight() {
		return this->height;
	}
};


// subclass or child class
class Student : public Person {
	// inheriting the Person by public mode
private:
	int rollNo;

public:
	// constructor of the sub class
	Student(string name, int age, double height, int rollNo) : Person(name, age, height) {
		cout << "initialized the Student data members..." << endl;
		this->rollNo = rollNo;
	}

	void display_info() {
		cout << "RollNo: " << this->rollNo << endl;

		// Not we can't access private data members directly, for that we need getter or setter method.
		cout << "Name: " << this->getName() << endl;
		cout << "Age: " << this->getAge() << endl;
		cout << "Height: " << this->getHeight() << endl;
	}
};
 
 
// multilevel inheritance
class Employee : public Student {

private:
	int empId;
	double salary;
	string role;
	string designation;
	string category;
	string language;

public:
	Employee(string name, int age, double height, int rollNo,
		int empId, double salary, string role, string designation, 
		string category, string language): 
		Student(name, age, height, rollNo) {

		this->empId = empId;
		this->salary = salary;
		this->role = role;
		this->designation = designation;
		this->category = category;
		this->language = language;

	}

	int get_empId() {
		return this->empId;
	}

	double get_salary() {
		return this->salary;
	}

	string get_role() {
		return this->role;
	}

	string get_designation() {
		return this->designation;
	}

	string get_category() {
		return this->category;
	}

	string get_language() {
		return this->language;
	}

	void show_info() {
		cout << "Name: " << this->getName() << endl;
		cout << "Id: " << this->empId << endl;
		cout << "Role: " << this->role << endl;
		cout << "Salary: " << this->salary << endl;
		cout << "Category: " << this->category << endl;
		cout << "Language: " << this->language << endl;

	}
	
};


Employee createEmployee();

int main() {

	
	Employee emp = createEmployee();
	emp.show_info();

	return 0;
}

// scan --> string, int double

void getString(string& str) {
	getline(cin, str);
	cin.ignore(100, '\n');
}


void getInt(int &Int) {
	cin >> Int;
	cin.ignore(100, '\n');
}


void getDouble(double &Double) {
	cin >> Double;
	cin.ignore(100, '\n');
}


Employee createEmployee() {

	string name = "";
	int age = 0;
	double height = 0;
	int rollNo = 0;
	int empId = 0;
	double salary = 0;
	string role = "";
	string designation = "";
	string category = "";
	string language = "";


	cout << "Enter Name: ";
	getString(name);

	cout << "Enter Age: ";
	getInt(age);

	cout << "Enter Height: ";
	getDouble(height);

	cout << "Enter empId No: ";
	getInt(empId);

	cout << "Enter Role: ";
	getString(role);

	cout << "Enter Designation: ";
	getString(designation);

	cout << "Enter category: ";
	getString(category);

	cout << "Enter language: ";
	getString(language);


	// now creating an instance of Employee
	Employee emp(name,age, height,0,empId,salary, role, designation, category, language);

	return emp;
}