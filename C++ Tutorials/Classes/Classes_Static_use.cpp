#include <iostream>
#include <stdlib.h>
using namespace std;
/*
    static variable:
        static variable are created once, they are allocated at the compile time.

        1. we don't need any class instance to access the static variable.
        2. Static variable are common for each instance of that class.
        3. memory address is shared to all instance.
*/

class Student
{
    // access modfiers -> private, protected, public.
private:
    string name;
    int age;
    float height;

public:
    // To initalize the private data member we need to use constructor.
    static int Count_Students; // static variable
    static Student *Studentx;  // this pointer will have the address of an array.

    // default constructor.
    Student()
    {
        name = "";
        age = 0;
        height = 0.0;

        Student::Count_Students++; // increasing the Count_Student variable by one.
        Student::Studentx[0] = this;
    }

    // parameterized constructor.
    Student(string Name, int Age, float Height)
    {
        // cout << "parameterized construstor is called." << endl;
        // assigning values during creation of object.
        name = Name;
        set_age(Age);       // set_age function is the setter for age.
        set_height(Height); // set_height is the setter for the height.

        Student::Count_Students++; // increasing the Count_Student variable by one.
    }

    void show_info()
    {

        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << endl;
    }

    // a method to set the age of the age attribute
    void set_age(int Age)
    {

        if (Age >= 18 && Age <= 80)
        {
            age = Age; // valid age.
        }
        else
        {
            cout << "\nInvalid age" << endl;
            // throw exception
        }
    }

    // a method to set the height of the height attribute
    void set_height(float Height)
    {

        if (Height > 3.5 && Height < 7.5)
        {
            height = Height; // valid age.
        }
        else
        {
            cout << "\nInvalid height: height must be in range [3.5, 7.5]" << endl;
            // throw exception
        }
    }

    // getter for age.
    int get_age() { return age; }

    // getter for height
    float get_height() { return height; }

    // getter for name
    string get_name() { return name; }

}; // ending with semicolon.

// initalization the static variable of Student.

int Student::Count_Students = 0;
Student *Student::Studentx = (Student *)malloc(sizeof(Student) * 4);

int main()
{
    system("cls");

    // creating the object of student it will increase the Count_Students
    Student st; // default constructor is called.
    Student st2("Saloni", 21, 5.6);
    Student st3("Komal", 21, 5.5);
    Student st4("Abhishek", 19, 5.6);

    cout << "count students: " << Student::Count_Students << endl;
}