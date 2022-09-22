#include <iostream>
#include <iomanip>
using namespace std;

#define WSIZE 15

/*---------------------------------------------------------
In this section we will learn about the multiple inheritance,
and we will learn how to use that inheritance in a defined
situation.

2. multiple inheritance.

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
        cout << setw(WSIZE) << left << "Name: " << setw(WSIZE) << left << this->name << endl;
        cout << setw(WSIZE) << left << "Age: " << setw(WSIZE) << left << this->age << endl;
        cout << setw(WSIZE) << left << "Height: " << setw(WSIZE) << left << this->height << endl;
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
class Student
{

private:
    int st_id;
    string subject;
    string std;

public:
    Student(string subject, string std, int st_id)
    {
        cout << "Student constructor has been called." << endl;

        this->subject = subject;
        this->std = std;
        this->st_id = st_id;
    }

    void stdisplay()
    {
        cout << setw(WSIZE) << left << "St Id: " << setw(WSIZE) << left << this->st_id << endl;
        cout << setw(WSIZE) << left << "Subject: " << setw(WSIZE) << left << this->subject << endl;
        cout << setw(WSIZE) << left << "Std: " << setw(WSIZE) << left << this->std << endl;
    }

    void st_update()
    {

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

class Employee
{

private:
    int emp_id;
    string department;
    string designation;

public:
    Employee(int emp_id, string department, string designation)
    {
        this->emp_id = emp_id;
        this->department = department;
        this->designation = designation;
    }

    void emp_display()
    {
        cout << setw(WSIZE) << left << "emp Id: " << setw(WSIZE) << left << this->emp_id << endl;
        cout << setw(WSIZE) << left << "Department: " << setw(WSIZE) << left << this->department << endl;
        cout << setw(WSIZE) << left << "Designation: " << setw(WSIZE) << left << this->designation << endl;
    }

    void inline_emp_display()
    {
        cout << setw(WSIZE) << left << this->emp_id
             << setw(WSIZE) << left << this->department
             << setw(WSIZE) << left << this->designation << endl;
    }
};

class Manager : private Person, protected Student, public Employee
{
private:
    float salary;
    int ControllingEmp = 0;
    Employee **UnderEmps = new Employee *[5];

public:
    Manager(float salary,
            int emp_id, string department, string designation,
            string subject, string std, int st_id, string name,
            int age, float height) : Person(name, age, height),
                                     Student(subject, std, st_id),
                                     Employee(emp_id, department, designation)
    {
        /// body of manger constructor.
        this->salary = salary;
    }

    void addEmp(Employee *emp)
    {
        this->UnderEmps[this->ControllingEmp] = emp;
        this->ControllingEmp++;
    }

    void MGdisplay()
    {
        this->display();
        this->stdisplay();
        this->emp_display();
        cout << setw(WSIZE) << left << "Salary:" << setw(WSIZE) << left << this->salary << endl;
    }

    void showUnderEmps()
    {
        cout << setw(WSIZE) << left << "Employee Id"
             << setw(WSIZE) << left << "Department"
             << setw(WSIZE) << left << "Designation" << endl;
        for (int i = 0; i < this->ControllingEmp; i++)
        {

            this->UnderEmps[i]->inline_emp_display();
        }
    }
};

int main()
{
    system("cls");

    /*---------------------------------------------------------
    float salary,
            int emp_id, string department, string designation,
            string subject, string std, int st_id, string name,
            int age, float height
    ---------------------------------------------------------*/
    Manager manager(50000.0, 123456, "Web Developer", "Manager", "Computer Science",
                    "PG", 1001, "Abhishek", 19, 5.7);

    manager.MGdisplay();

    Employee *k = new Employee(123465, "Web Developer", "Rookie");

    Employee *s = new Employee(123468, "Web Developer", "Senior");

    manager.addEmp(k);
    manager.addEmp(s);

    //  Now we will check that our Under Employing details.
    printf("\n\n");
    manager.showUnderEmps();

    return 0;
}