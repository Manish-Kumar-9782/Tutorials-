#include <iostream>
#include <stdlib.h>
using namespace std;
/*
    friend funciton:

        1. friend function has 'friend' keyword before return type.
        2. friedn function can access the private member of object.
        3. we need to declare the friend function inside that class, who want became the friend.
        4. we need to define its defination outside the class. (global scope.)
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

    friend void my_friend_data(Student &st); // making a friend funciton.
};                                           // ending with semicolon.

void my_friend_data(Student &st)
{
    cout << "from friedn function " << endl;

    // Note: here we are able to access all the private members of st object.
    cout << "Name: " << st.name << endl;
    cout << "Age: " << st.age << endl;
    cout << "Height: " << st.height << endl;
    printf("\n\n");
}
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

    my_friend_data(st2);
}