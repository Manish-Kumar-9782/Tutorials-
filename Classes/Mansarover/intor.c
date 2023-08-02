#include<stdio.h>


// global scope


/*
    data types : int, float, double, char

    to create a variable from above defined data types we have
    following syntax.

    <data-type> <var_name>;
    e.g: int myVar;

    printing values syntax:

    printf(format_string, ...,variables)

    format-string: "this is string" (enclosed by ")

    format_string: it contains the message with the format specifiers.

    format_specifiers: special character to define the format of our data values
     inside the string.

     %d: integer
     %f : float
     %c : char
     %s : string
     %lf : double
*/
int var1;  // declaration of variable
// global varaible

void main(){
// local scope

    // local varaible
    int var2; // declaration

    // assigning a value to var2 variable.
     var2 = 40;

     int var3 = 45; // initalization


    printf("hello world\n");
    // here \n is newline character to create a new line

    printf("value of var2: %d\n",var3);

    // printing all three variable values.
    printf("var1:%d, var2:%d, var3:%d", var1,var2,var3);
}

