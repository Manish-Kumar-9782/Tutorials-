#include <iostream>
using namespace std;

/*---------------------------------------------------------
in this section we will learn about the template concept. what
is the need of template and how to use, when to use.

1. function template
2. class template

---------------------------------------------------------*/

/*
    Program: suppose that we want add two number, number can be an integer,
    float,double, short int, long int.

    if we follow the general syntax for calculation on these various kind
    of data types then we need to make a separate add for each data type.

    in other we need to follow the function overloading.

*/

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

float add(float a, float b)
{
    return a + b;
}

// using the template for this kind of situation to avoid redefining
// the function block.

template <typename Type>
Type Add(Type a, Type b)
{
    return a + b;
}

template <typename Type1, typename Type2>
Type1 Addx(Type1 a, Type2 b)
{
    return a + b;
}

int main()
{
    system("cls");

    // using normal overloaded funtions.
    cout << "result of int add: " << add(2, 3) << endl;
    cout << "result of float add: " << add(2.02, 3.365) << endl;
    cout << "result of double add: " << add(2.264, 3.156) << endl;

    cout << "\n\nUsing templates:\n"
         << endl;
    // Using the template function .
    float x = 2.345, y = 34.4543;
    cout << "result of int add: " << Add(2, 4) << endl;
    cout << "result of float add: " << Add(x, y) << endl;
    cout << "result of double add: " << Add(2.264, 3.156) << endl;
    // cout << "result of string add: " << Add("hello ", "Welcome") << endl;

    cout << "\n\nUsing multiple parameterised template \n"
         << endl;
    cout << "result of int + float: " << Addx(10, 2.34) << endl;
    cout << "result of float + int: " << Addx(2.34, 10) << endl;

    return 0;
}