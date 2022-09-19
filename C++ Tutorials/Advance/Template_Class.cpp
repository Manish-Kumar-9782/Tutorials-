#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn aobut the class template, how to
make them and use them.

Class Template: class templates are defined in same way as function
template defined. when a class uses the template then the class is
know as the generic class.

Syntax:
    template <class Type>
    class class_name{
        // body of the class.
    }

class: here class keyword show that the next word is a type not an identifier.
    we can use the typname instead of the class we mis-understand the term.

Type: it is a placeholder for the data type which will be used in our class.

---------------------------------------------------------*/

// A simple class to add data.

template <class Number>
class Add
{
    // it will two variable.
public:
    Number a;
    Number b;

    Add(Number x, Number y)
    {
        a = x;
        b = y;
    }

    void result()
    {
        cout << "Result: " << a + b << endl;
    }
};

int main()
{

    system("cls");

    /*
    Now we will make the instance of the Add class but here
    we need to define that what kind of data we will use
    in our class.
    */

    // adding the integer
    Add<int> add_int(3, 4);
    add_int.result();

    // adding float
    Add<float> add_float(4.3, 5.6);
    add_float.result();

    // adding double
    Add<double> add_double(4.55, 6.300);
    add_double.result();

    // Adding strings
    Add<string> add_string("Hello ", "Welcome");
    add_string.result();

    return 0;
}