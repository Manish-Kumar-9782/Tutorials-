#include <iostream>
#include <string>

using namespace std;

// class name must be capitalized
class Student
{
    // by default all data members and member functions are
    // private.
    string name;
    int age;
    double height;

    // creating a constructor.
    // Note: constructor name is same as the class name
    /*
        constructor:
        it is a special kind of function.
            1. it does not have any return type.
            2. called when the object is created.
            3. used to initialize the object's data members.

        constructor type:
            1. default constructor
            2. parameterized constructor
            3. copy constructor

    */

public:
    // 1. default constructor
    // this constructor does not have any parameter.
    Student()
    {
        this->name = "Unknown";
        this->age = 3;
        this->height = 3;
        cout << this->name << " student is created with default constructor.." << endl;
    }

    // 2. parameterized constructor
    Student(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
        cout << this->name << " student is created with constructor.." << endl;
    }

    void show_info()
    {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Height: " << this->height << endl;
    }
};

int main()
{

    Student st;

    Student st2("Aashu", 20, 5.7);

    st.show_info();
    st2.show_info();

    return 0;
}