#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the multiple inheritance, how to define
the multiple inheritance and use it in our program.


`3. Multiple Inheritance: ` Multiple Inheritance is a feature
of C++ where a class can inherit from more than one class.
---------------------------------------------------------*/

// suppose that we have two different class
// Person and Student.
// A sub class Employee will inherit both of these class.

class Person
{

private:
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
};
/*---------------------------------------------------------*/

class Student
{
private:
    int id;
    string std;
    string subject;

public:
    Student(int id, string std, string subject)
    {
        this->id = id;
        this->std = std;
        this->subject = subject;
    }
};
/*---------------------------------------------------------*/

// Employee class will inherit both the Person and Student.
class Employee : private Person, Student
{
    // all the inherited data member and functions will be private.
private:
    int empid;
    string department;
    string designation;
    string roll;

public:
    // Now here we need to initialize the Person and
    // Student Constructor also by taken their args value
    // from Employee .
    Employee(int empid, string department, string designation, string roll, string name, int age, float height,
             int id, string std, string subject) : Person(name, age, height),
                                                   Student(id, std, subject)
    {
        // Note: that here we have initialized the Person and Student
        // constructor by using the member initialization concept.
        // Now we need to assign the rest of the data members.
        this->empid = empid;
        this->department = department;
        this->designation = designation;
        this->roll = roll;
    }
};

int main()
{
    system("cls");

    Employee emp(1233, "Developer", "Manger", "Team Mangement",
                 "Manish", 36, 5.7, 321, "PG", "AI");

    return 0;
}