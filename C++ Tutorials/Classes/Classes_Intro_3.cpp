#include <iostream>
using namespace std;
/*
    object: instance, object are instance of clasees.

    constructor: it is a mechanism which runs during the creation/instantition of the object of a class.

    default constructor: initalize the object data members, attribute.

    keyword is used to declare to a class: class
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

    // default constructor.
    Student()
    {
        cout << "default constructor of Student is called." << endl;
        name = "";
        age = 0;
        height = 0.0;
    }

    // parameterized constructor.
    Student(string Name, int Age, float Height)
    {
        // cout << "parameterized construstor is called." << endl;
        // assigning values during creation of object.
        name = Name;
        set_age(Age);
        set_height(Height);
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

        if (Age > 18 && Age < 80)
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

int main()
{
    system("cls");

    Student st;
    // st.name;
    // Student st2("abhishek", 10, 9.7);

    cout << "Student st info: " << endl;
    st.show_info();

    cout << "\n\nStudent st2 info: " << endl;
    Student st2("abhishek", 10, 9.7);
    st2.show_info();

    // editing the age.
    st2.set_age(19);
    st2.set_height(5.7);
    // st2.show_info();

    // using getter to access the value.
    cout << "st2 Name: " << st2.get_name() << endl;
    cout << "st2 Age: " << st2.get_age() << endl;
    cout << "st2 Height: " << st2.get_height() << endl;
}