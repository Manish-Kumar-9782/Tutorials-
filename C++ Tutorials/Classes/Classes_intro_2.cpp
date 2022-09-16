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
        age = Age;
        height = Height;
    }

    void show_info()
    {

        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << endl;
    }

}; // ending with semicolon.

int main()
{
    system("cls");

    Student st;
    Student st2("abhishek", 20, 5.7);
    // st.name;

    cout << "Student st info: " << endl;
    st.show_info();

    cout << "\n\nStudent st2 info: " << endl;
    st2.show_info();
}