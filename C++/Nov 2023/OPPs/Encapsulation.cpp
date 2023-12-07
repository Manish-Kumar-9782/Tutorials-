#include <iostream>
#include <string>

using namespace std;

class Student
{

    // all data members are private
private:
    string name;
    int rollno;
    int std; // a data member of Student not a namespace.

public:
    Student(string name, int rollno, int std)
    {
        // setting all the data members by using setter method.
        this->setName(name);
        this->setRollno(rollno);
        this->setStd(std);
    }

    // we need to create getter or setter method.
    // setFunctionName getFunctionName

    void setName(string name)
    {
        this->name = name;
    }

    void setRollno(int rollno)
    {
        this->rollno = rollno;
    }

    void setStd(int std)
    {
        this->std = std;
    }

    string getName()
    {
        return this->name;
    }

    int getRollno()
    {
        return this->rollno;
    }

    int getStd()
    {
        return this->std;
    }
};

int main()
{

    Student st("Ashutosh", 1234, 11);
    cout << "student name: " << st.getName() << endl;
    return 0;
}