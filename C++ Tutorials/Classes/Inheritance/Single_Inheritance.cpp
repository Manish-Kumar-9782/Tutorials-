#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the type of inheritance and will
see that how to work on them one by one.

1. Single inheritance
2. Multilevel inheritance
3. Multiple inheritance
4. Hierarchical inheritance
5. Hybrid inheritance

`1. Single Inheritance:` In Single Inheritance, a class is only
inherit from only one class. or in other word only one subclass is
inherited by one base class only.
---------------------------------------------------------*/

class Person
{

private:
    string name;
    int age;
    float height;

public:
    Person(string name, int age, float height)
    {
        // constructor of the Person class.
        this->name = name;
        this->age = age;
        this->height = height;
    }
};
/*---------------------------------------------------------*/

// Now we will inherit our Person into the Student class.

class Student : private Person
{
private:
    int id;
    string std;
    string subject;

public:
    Student(string name, int age,
            float height, int id, string std,
            string subject) : Person(name, age, height) // initiating the Person constructor.
    {
        this->id = id;
        this->std = std;
        this->subject = subject;
    }
};

int main()
{
    system("cls");

    // Note here Creating object of sub class will invoke
    // the constructor ob base classes.

    Student st("manish", 24, 5.7, 12345, "PG", "AI");

    return 0;
}