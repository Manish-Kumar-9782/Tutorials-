#include <iostream>
#include <iomanip>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the multilevel inheritance, in this kind
of inheritance a single chain of inheritance take place.

2. multilevel inheritance.

---------------------------------------------------------*/

class Person
{
private:
    // Note: these private member will not be inherited in derived class.
    // it means we can not directly access these data members.
    // Note: we need to use the public member to use them.
    string name;
    int age;
    float height;

public:
    Person(string name, int age, float height)
    {
        cout << "Person constructor has been called." << endl;
        this->name = name;
        this->age = age;
        this->height = height;
    }

    void display()
    {
        cout << setw(15) << left << "Name: " << setw(15) << left << this->name << endl;
        cout << setw(15) << left << "Age: " << setw(15) << left << this->age << endl;
        cout << setw(15) << left << "Height: " << setw(15) << left << this->height << endl;
    }

    void update_person()
    {
        string name;
        int age;
        float height;

        cout << "Enter the Name" << endl;
        cin >> name;

        cout << "Enter the age" << endl;
        cin >> age;

        cout << "Enter the height" << endl;
        cin >> height;

        this->name = name;
        this->age = age;
        this->height = height;
    }
};

/*---------------------------------------------------------*/
class Student : private Person
{

private:
    int st_id;
    string subject;
    string std;

public:
    Student(string subject, string std, int st_id,
            string name, int age, float height) : Person(name, age, height)
    {
        cout << "Student constructor has been called." << endl;

        this->subject = subject;
        this->std = std;
        this->st_id = st_id;
    }

    void stdisplay()
    {
        this->display();
        cout << setw(15) << left << "St Id: " << setw(15) << left << this->st_id << endl;
        cout << setw(15) << left << "Subject: " << setw(15) << left << this->subject << endl;
        cout << setw(15) << left << "Std: " << setw(15) << left << this->std << endl;
    }

    void st_update()
    {
        this->update_person();

        int st_id;
        string subject;
        string std;

        cout << "Enter student id:" << endl;
        cin >> st_id;

        cout << "Enter student subject: " << endl;
        cin >> subject;

        cout << "Enter student std: " << endl;
        cin >> std;

        this->st_id = st_id;
        this->subject = subject;
        this->std = std;
    }
};

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

// now here we will make the employee class which will inherit the
// student class.

class Employee : private Student
{

private:
    int emp_id;
    string department;
    string designation;

public:
    Employee(int emp_id, string department, string designation,
             string subject, string std, int st_id,
             string name, int age, float height) : Student(subject, std, st_id, name, age, height)
    {
        this->emp_id = emp_id;
        this->department = department;
        this->designation = designation;
    }

    void emp_display()
    {
        this->stdisplay();
        cout << setw(15) << left << "emp Id: " << setw(15) << left << this->emp_id << endl;
        cout << setw(15) << left << "Department: " << setw(15) << left << this->department << endl;
        cout << setw(15) << left << "Designation: " << setw(15) << left << this->designation << endl;
    }
};

int main()
{
    system("cls");
    /*---------------------------------------------------------
    string subject, string std, int st_id,
            string name, int age, float height
    ---------------------------------------------------------*/
    Employee emp(91112, "Computer Science", "Managing Director",
                 "BCA", "1st year", 10101, "Abhishek", 19, 5.6);
    emp.emp_display();
    // emp.stdisplay(); // cannot access private member

    // st.st_update();

    // printf("\n\n");
    // emp.emp_display();
    return 0;
}