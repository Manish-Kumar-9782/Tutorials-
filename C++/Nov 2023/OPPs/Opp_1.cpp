#include <string>
#include <iostream>

using namespace std;

class Student
{

    string name;
    int age;
    double height;

public:
    Student(string name, int age, double height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

int main()
{

    Student st("bharat", 21, 5.6);

    return 0;
}