#include <iostream>
#include <string>

using namespace std;

/*
    Operator Overloading:

    it is same as function overloading except some restrictions.

    1. we have to use the return type according to the operator and Operation.
    2. limited number of arguments
*/

struct Person
{
    string name;
    int age;
    float height;
};

// operator overloading for output operator (<<)
// returning the ostream object reference
ostream &operator<<(ostream &COUT, Person &pr)
{
    COUT << "Person{ Name: " << pr.name << ", "
         << "Age: " << pr.age << ", "
         << "Height: " << pr.height << "}" << endl;

    return COUT;
}

main()
{

    Person pr;

    pr.name = "Aashu";
    pr.age = 20;
    pr.height = 5.7;

    // reference variable.
    string &name_ref = pr.name;

    // cout << pr;
    // cout -> isotream;
    // pr -> Person

    cout << "Name: " << pr.name << endl;
    name_ref = "Aashutosh";
    cout << "Name: " << pr.name << endl;

    cout << pr;
    return 0;
}