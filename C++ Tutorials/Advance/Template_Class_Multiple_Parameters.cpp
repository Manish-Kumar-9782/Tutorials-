#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will see class templates with multiple parameter.

class template can have multiple parameter like function template do,
each parameter is separated by comma.

Syntax:
    template <class T1, class T2, ... , class Tn>
    class class_name{
        // body of class
    }
---------------------------------------------------------*/

template <class type1, class type2, class type3, class type4>
class Dummy
{

public:
    type1 value1;
    type2 value2;
    type3 value3;
    type4 value4;

    Dummy(type1 t1, type2 t2, type3 t3, type4 t4)
    {
        value1 = t1;
        value2 = t2;
        value3 = t3;
        value4 = t4;
    }

    void display()
    {
        cout << "vlaue1: " << value1 << endl;
        cout << "vlaue2: " << value2 << endl;
        cout << "vlaue3: " << value3 << endl;
        cout << "vlaue4: " << value4 << endl;
    }
};

int main()
{
    system("cls");

    // using the template class
    Dummy<int, float, double, string> test(10, 10.123, 10.35534, "Hello welcome");

    // Dummy<auto, auto, auto, auto> auto_test(45.343, 34, 532.3523, "Hello");
    // auto is not allowed here.

    test.display();
    return 0;
}