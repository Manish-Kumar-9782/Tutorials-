#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the the multilevel inheritance. and
how to use the multilevel inheritance.

Multilevel inheritance: multilevel inheritance is type of inheritance in
which a chain is made of inheritance, like Person is inherited by Student
class, and Student class is inherited by the Employee class.

Now in this kind of inheritance the last derived class inherits all the
of the above class data members.

Here is the example of multilevel inheritance.
---------------------------------------------------------*/
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

// Student class will inherit the Person class.
class Student : public Person
{
private:
    int id;
    string std;
    string subject;

public:
    // Here we need to initialize the Person class constructor
    // arguments.
    Student(int id, string std, string subject,
            string name, int age, float height) : Person(name, age, height)
    {
        this->id = id;
        this->std = std;
        this->subject = subject;
    }
};

/*---------------------------------------------------------*/
// Now here we will define another class which will inherit the Student.

class Employee : public Student
{

private:
    int emp_id;
    string designation;
    string department;

public:
    // Now we need to make a constructor.
    Employee(int empid, string designation, string department,
             int id, string std, string subject,
             string name, int age, float height) : Student(id, std, subject, name, age, height)
    {
        this->emp_id = empid;
        this->designation = designation;
        this->department = department;
    }
};

int main()
{
    system("cls");

    return 0;
}