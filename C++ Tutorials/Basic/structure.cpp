#include <iostream>
#include <string>

using namespace std;


// In this section we don't have to use the typedef to make an alias name
// to short our structure data type.

// we can directly make variable by using the Student identifier.

struct Student
{
    string name;
    int age;
    float height;
};

int main()
{

    Student st;

    cout << "Enter your name: ";
    cin >> st.name;

    cout << "Enter your age: ";
    cin >> st.age;

    cout << "Enter you height: ";
    cin >> st.height;

    cout << "your have entered the following details."<<endl;

    cout << "Your name: " << st.name << endl;
    cout << "Your age: " << st.age << endl;
    cout << "Your height: " << st.height << endl;

    return 0;
}
