#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this sectino we will see the sizeof() oeprator and the application
of the sizeof() operator in different senerio.

The sizeof() operator is an operator that evalutes the size of dat type,
constants, variable. it is a compile-time operator as it returns the size
of any varaible or a constant at the compliation time.

the size, which is calculated by the sizeof() operator, is  the amount of RAM
occupied in the computer.

Syntax: sizeof(data_type);

Here "data_type" can be the dat type of the data, varaibles, constants,
unions, stuructures, or any other user-defined data type.

sizeof() operator can be applied to the following operand:

    -> when an operand is of data type.
    -> when an operand is of class type.
    -> when an operand is of array type.
    -> when an operand is of pointer type.
    -> when an operand is an expression.
---------------------------------------------------------*/

// function for each use.

void operand_data_type();
void operand_class_type();
void operand_array_type();
void operand_pointer_type();
void operand_expression();

int main()
{
    system("cls");

    // operand data_type
    operand_data_type();

    // operand class_type
    operand_class_type();

    // operand array_type
    operand_array_type();

    // operand pointer_type
    operand_pointer_type();

    // operand expression
    operand_expression();

    return 0;
}

void operand_data_type()
{
    // 1. when an operand a data_type.
    /*
        if the parameter of a sizeof() operator contains the data type of a varaible,
        then the sizeof() operator will return the size of the data type.
        */

    cout << "Size of interger data type: " << sizeof(int) << endl;
    cout << "Size of float data type: " << sizeof(float) << endl;
    cout << "Size of character data type: " << sizeof(char) << endl;
    cout << "Size of double data type: " << sizeof(double) << endl;
    cout << "Size of string data type: " << sizeof(string) << endl;
}

class Student
{
    int age;      // 4 byte for 32-bit machine
    float height; // 4 byte fro 32-bit machine
    string name;  // 1 byte per char

    // Note that due to the concept of structur padding our final
    // size will not match with our calculation.
};

void operand_class_type()
{
    // Now we will use the Student class to work with the
    // size of the user-defined class depends on the its variable.
    Student st;
    cout << "size of the Student class object.: " << sizeof(st) << endl;
}

void operand_array_type()
{
    int arr[] = {10, 20, 30, 40, 50};
    std::cout << "Size of the array 'arr' is : " << sizeof(arr) << std::endl;

    // Note if an array is passed to a function and we use the sizeof
    // operator in that function then it will show the size of pointer
    // according to the machine size.
}

void operand_pointer_type()
{
    int *Integer = new int(10);
    float *Float = new float(10);
    char *Char = new char('a');

    cout << "Size of integer pointer: " << sizeof(Integer) << " and sizeof value pointing by it: " << sizeof(*Integer) << endl;
    cout << "Size of float pointer: " << sizeof(Float) << " and sizeof value pointing by it: " << sizeof(*Float) << endl;
    cout << "Size of char pointer: " << sizeof(Char) << " and sizeof value pointing by it: " << sizeof(*Char) << endl;
}

void operand_expression()
{
    // sizeof of expressions.

    int num1 = 40;
    double num2 = 40.40;

    cout << "Size of expression: " << sizeof(num1 + num2) << endl;
}