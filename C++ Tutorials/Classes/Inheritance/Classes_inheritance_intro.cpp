#include <iostream>
#include <iomanip>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the inheritance in class, what is
inheritance and how to use inheritance.

Inheritance: The capability of a "class" to derive properties and characteristcs
from another class is called inheritance.

Inheritance is a feature or a process in which new classes are created from
the existing classes. The new class created is called "derived class" or
"Child class" and the existing class is known as the "base class" or
"parent class". The derived class now is said to be inherited from the base
class.

Note: all the additional key terms are defined in the Readme file.
---------------------------------------------------------*/
// first of all we are making the base class.

// Base class as Person

class Person
{

    string name;
    int age;
    float height;

public:
    Person(string name, int age, float height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    void displayPerson(int fw = 12)
    {
        cout << setw(fw) << left << "Name: " << setw(fw) << left << this->name << endl;
        cout << setw(fw) << left << "Age: " << setw(fw) << left << this->age << endl;
        cout << setw(fw) << left << "Height: " << setw(fw) << left << this->height << endl;
    }
};

// Now we will inherit the person class into the Student class.
// Note: all the private data member will not be inherited.
// if we want to access those private data member then we need
// to use the public member method or protected member method.
class Student : private Person
{
    string course;
    int rollno;
    string std;

public:
    Student(string name, int age, float height,
            string course, int rollno,
            string std) : Person(name, age, height)
    // invoking the parameterized constructor.

    // Read the Readme file to see the full description to understand that
    // how constructor is called.
    {
        this->course = course;
        this->rollno = rollno;
        this->std = std;
    }

    void displayStudent(int fw = 12)
    {
        this->displayPerson(); // first displaying the Person details.
        // after that we will display the Student data.
        cout << setw(fw) << left << "Course: " << setw(fw) << left << this->course << endl;
        cout << setw(fw) << left << "RollNo: " << setw(fw) << left << this->rollno << endl;
        cout << setw(fw) << left << "Class: " << setw(fw) << left << this->std << endl;
    }
};

int main()
{
    system("cls");

    // Now we will create an object of the Student class.
    Student st("manish", 26, 5.7, "Artificial Intelligence", 2341, "PG");

    st.displayStudent();

    return 0;
}