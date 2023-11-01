#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
    double height;

    Person(string name, int age, double height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
        cout << "A Person with name " << this->name << " created.." << endl;
    }

    void greeting()
    {
        cout << "Hello, my name is " << this->name << " nice to meet to you.." << endl;
    }
};

ostream &operator<<(ostream &COUT, Person &pr)
{
    COUT << "Person{ Name: " << pr.name << ", "
         << "Age: " << pr.age << ", "
         << "Height: " << pr.height << "}" << endl;

    return COUT;
}

main()
{

    Person pr("Bharat", 20, 5.6);

    Person pr2("Aashutosh", 20, 5.7);

    Person pr3("Mohit", 21, 5.8);

    pr.greeting();
    pr2.greeting();
    pr3.greeting();
    return 0;
}