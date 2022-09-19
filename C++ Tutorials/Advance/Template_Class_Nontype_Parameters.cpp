#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will see the nontype template argument , what are
they and how to use them.

The template can contain multiple arguments, and we can also use the
non-type arguments in addtion to the type T argument, we can also use
other types of arguments such as string, function names, constant expression
and built-in types.

Syntax:
    template <class type, int a>
    class Student{
        T arr[a]// here a is the size of array.
        // T is the type of array items.
    }
---------------------------------------------------------*/

template <class type, int s>
class VectorX
{

public:
    int length = s;
    type elements[s]{0};

    void insert(type t, int index)
    {

        if (index >= 0 && index < length)
        {
            elements[index] = t;
        }
        else
        {
            cerr << "invalid array index." << endl;
        }
    }

    void display()
    {
        cout << "array: [";
        for (int i = 0; i < length; i++)
        {
            if (i != length - 1)
                cout << elements[i] << ",";
            else
                cout << elements[i] << "]" << endl;
        }
    }
};

int main()
{
    system("cls");

    VectorX<char *, 5> Names;
    // Not since string is not a primitive data type so here we need
    // to use the char* to store the reference of given string.
    // so we can access that string by using the pointer.

    Names.insert("Manish", 0);
    Names.insert("Rahul", 1);
    Names.insert("Sagar", 2);
    Names.insert("Yogi", 3);
    Names.insert("Nikhil", 4);

    Names.display();

    return 0;
}