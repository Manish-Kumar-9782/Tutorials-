#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will learn about the void pointer and we will se that
how it works in our programs.

Void Pointer: A void pointer is a general-purpose pointer that can
hold the address of any data type, but it is not associated with
any data type.

Syntax: void *ptr;

In C++, we cannot assign the address of a variable to the variable of a different
data type.for example if we want to assign a float variable address to
an pointer to int then it will throw an error.

int *ptr;
float a = 34235.45345;
ptr = &a; //  error
---------------------------------------------------------*/

void cross_pointer();    // assigning differnt variable address.
void void_pointer();     // example of use of void pointer.
void void_typecasting(); // assigning void pointer to another pointer.

int main()
{
    system("cls");

    void_pointer();
    void_typecasting();
    return 0;
}

void cross_pointer()
{
    int *ptr;
    float ft = 342.35234;

    // ptr = &ft; // assigning to cross pointer reference.
}

// if we want to store a differnt kind of data variable address into a
// pointer then we need to use the void pointer.

void void_typecasting()
{

    void *vptr; // a void pointer
    int *iptr;  // an integer pointer

    int data = 10;

    // storing the data address to void pointer
    vptr = &data;

    // now we will assign this to the iptr;
    iptr = (int *)vptr;

    // if we don't do this
    // iptr = vptr; // error

    cout << "address of the data varaible: " << &data << endl;
    cout << "address pointing by void pointer: " << vptr << endl;
    cout << "address pointing by int pointer: " << iptr << endl;
}

void void_pointer()
{
    void *ptr;
    float ft = 342.35234;

    ptr = &ft; // assigning the ft address to void pointer.

    cout << "address of float variable: " << &ft << endl;
    cout << "address pointing by void ptr: " << ptr << endl;
}
