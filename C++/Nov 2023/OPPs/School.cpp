#include <iostream>
#include <string>

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

    void show_info()
    {
        cout << "Student( " << name << " , "
             << age << " , " << height
             << ")" << endl;
    }
};

class School
{

    string name;
    Student *students[10]; // to hold the student object reference.
    // Student students[10]  to hold student objet
    int nStudents = 0; // number of students

public:
    School(string name)
    {
        this->name = name;
    }

    void add_student()
    {
        string name;
        int age;
        double height;

        cout << "Student Name: ";
        cin >> name;

        cout << "Student age: ";
        cin >> age;

        cout << "Student height: ";
        cin >> height;

        Student *st = new Student(name, age, height);
        this->students[this->nStudents++] = st;
        // student[0] = st;
    }

    void add_student(string name, int age, double height)
    {
        Student *st = new Student(name, age, height);
        this->students[this->nStudents++] = st;
    }

    void listStudents()
    {
        for (int i = 0; i < this->nStudents; i++)
        {
            this->students[i]->show_info();
        }
    }
};

int main()
{
    School techInnovation("TechInnovation");

    techInnovation.add_student("mohit", 21, 6.1);
    techInnovation.add_student("bharat", 20, 5.5);

    char ch = ' ';

    while (1)
    {
        system("cls");
        techInnovation.listStudents();
        cout << "================================================================" << endl;

        cout << "1. add student " << endl;
        cout << "2. close" << endl;

        cin >> ch;

        switch (ch)
        {
        case '1':
            techInnovation.add_student();
            break;
        case '2':
            ch = 'q';
            break;
        }

        if (ch == 'q')
        {
            break;
        }
    }

    return 0;
}