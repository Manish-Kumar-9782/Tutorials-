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
    // making a constructor
    string myname;
    int myage;

    // here we can access the public member by using the '.' member operator,
    // The disadvantage of public attribute is that we dont have any control over the
    // assignment operation.

    // If we want to make some restriction on the assignment then we need to
    // define some rule make the attributes as private.

}; // ending with semicolon.

int main()
{
    system("cls");

    Student st;
    // st.name;
    st.myname;

    cout << "Enter the student name: ";
    cin >> st.myname;

    cout << "Enter the student Age: ";
    cin >> st.myage;

    cout << "student st myname: " << st.myname;
    cout << "student st myage: " << st.myage;
}