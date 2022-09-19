#include <iostream>
using namespace std;

/*---------------------------------------------------------
In this section we will see what are pointer in C++ and how to
use them in our program.

1. Pointer reduces the code and improves the performance, it is used to
 retrieving strings, trees etc. and used with arrays, structurs and
 functions.

2. we can return multiple values from function using pointers.

3. it makes us able to access any memory location in the computer's
 memory.
---------------------------------------------------------*/

// Now we will create a pointer by using the * (asterisk)

void swap_integer(int *, int *); // swap integers.

int main()
{
    system("cls");

    int *a = nullptr, num = 10;
    char *ch = nullptr, Char = 'X';

    // Now if we assign the address of the num and Char variable
    // to their respective pointer the we need to use the
    // below syntax.

    a = &num;   // assigning the address of the num to pointer a.
    ch = &Char; // assigning the address of the Char to pointer ch.

    cout << "number is located at " << a << " in memory and the value is: " << *a << endl;
    cout << "character is located at " << (void *)ch << " in memory and the value is: " << *ch << endl;

    // Note here we have used the *a, *ch to dereference, it means we are
    // accessing the value stored at that address.

    // Note: since char* pointer works differntly here so we need to use the
    //  explicitly type casting to print the address of the character which is
    //  pointed by the char* pointer.

    return 0;
}

void swap_integer(int *a, int *b)
{

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}