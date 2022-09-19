#include <iostream>
using namespace std;
/*
    In this section we will see how to create the array of pointer and how to use it.

    1. first we will make the array of simple type which will be a 1-D array.
    2. after creating the array of 1-D array we will create the 2-D array which will be array of pointers.

    Note: array of pointers can be usefull whenever we want to store the reference of multiple object in an \
        array.

    Note:

*/

void static_oneD_Array(); // a function for static oneD array.
void static_twoD_Array(); // a function for static twoD array.

void dynamic_oneD_Array(); // a function for dynamic oneD array with new keyword
void dynamic_twoD_Array(); // a function for dynamic twoD array with new keyword

int main()
{
    system("cls"); // clearing the screen

    // 1-D array static
    // static_oneD_Array();

    // 2-D array static
    // static_twoD_Array();

    // 1-D array dynamic
    // dynamic_oneD_Array();

    // 2-D array dynamic
    dynamic_twoD_Array();
}

void static_oneD_Array()
{
    // now we will create the simple array of which will store the integers.

    int array[10]{12, 23, 45, 67, 89, 12, 34, 56, 78, 90};

    for (int i : array)
    {
        cout << i << " ";
    }
}

void static_twoD_Array()
{
    // now we will create a twod array which which will store the ingegers.

    int array[2][5]{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}};
    printf("\n\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void dynamic_oneD_Array()
{
    // in this section we will create a one array dynamically by using the pointers and new
    // keyword.

    // we will take the input from the user to set the size of the variable.

    int size{0}; // initalizing the size.

    cout << "Enter the size of arary.";
    cin >> size;

    int *numbers = new int[size]; // creating the array of integer type dynamically.

    cout << "Enter the numbers";

    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    cout << "\n\n"
         << "Entered Numbers.";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
}

void dynamic_twoD_Array()
{
    // Now in this section we will create a 2-D array by using the pointers which will
    // hold the reference of the object to represent this example we will use the struct.

    struct student
    {
        string name;
        int age;

        void show()
        {
            cout << name << " " << age << endl;
        }
    };

    int size; // size: number of students to create.

    cout << "Size of students: ";
    cin >> size;
    // Now we need to use the double astrisk on the pointer variable which will hold the
    // reference of the students.
    student **Students = new student *[size];

    // now this will create the memory block which will has the reference pointer
    // these pointer now can store the students object dynamically.

    // Now we need to create the objects dynamically and need to store that object
    // in our 2-D pointer array.

    student *st; // a pointer which can hold the newly created students.
    for (int i = 0; i < size; i++)
    {
        st = new student;
        cout << "Enter the student " << i << " details: " << endl;
        cin >> st->name >> st->age;
        // Now we need to place the st at its position in the **student pointer array.
        Students[i] = st;
        system("cls");
    }

    // Now we need to print the the each object after getting the details of each object.
    cout << "Entered Students Details: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "student no " << i << " Entry:\t";
        Students[i]->show();
        printf("\n");
    }
}