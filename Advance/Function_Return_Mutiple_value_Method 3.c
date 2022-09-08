#include <stdio.h>
#include <stdlib.h> // to use the malloc without warning.
#include <string.h>

//	In this section we will make a function which will return  multiple values by using the
// Union by which we can return the different kind of values.

// In this section we don't have make the structure we will  since we will use the array reference.

// General Idea: in this section we will make a union which can hold the multiple data value at the same address
// now we will make an array of unions which will be used to store the differnt values.

void swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}

//

typedef union values
{
    int Integer;
    char String[20];
    float Float;
} val;

// now we will make a fuction which will return the muliple values.

val *return_multiple_values()
{
    // Now we will make an array of val union which can hold the multiple values.
    val *rvalues = (val *)malloc(sizeof(val) * 3);
    // since we will return three different values hence we have created three location for
    // the our three different values.

    strcpy(rvalues[0].String, "Hello");
    rvalues[1].Integer = 2;
    rvalues[2].Float = 2.3;

    return rvalues;
}

void main()
{

    val *values;
    values = return_multiple_values();

    // Now we need to print the values.

    printf("first values: %s\n", values[0].String);
    printf("second values: %d\n", values[1].Integer);
    printf("third values: %.2f\n", values[2].Float);
}
