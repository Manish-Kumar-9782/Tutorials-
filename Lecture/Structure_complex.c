// In this section we will make a program to represent a complex number computation by using a structure:

/*
    Program: Explain how complex number can be represented using structures. Write two C funtions: onte to return the usm of to
    complex number passed as parameters.

    // In this section we will see , how to pass a structure and return it.
*/

#include<stdio.h>
#include<math.h> // to perform square root and other compuation.

// first of all we will define the defination of the structure of complex number.
// we will use typedef struct to make it short declaration.

typedef struct complex
{
    double real; // real part of the complex number
    double img; // imagenary parto of the complex numbrer.
}comp; // allias name of the sturcture name defination.

// Now we will make a main function and inside this we will make some variable of the comp structure.
// also first we will make functions.

// Function to return the sum of two omplex numbers.
comp add(comp a, comp b){

    // Now here comp a and comp b are the variable of the comp structure.
    // now we will make a third comp variable in which we will store the result.
    comp c;

    // adding real and imagenary part individually.
    c.real = a.real + b.real;
    c.img = a.img + b.img;

    return c; // returning a structure variable.
}

comp product(comp a, comp b){

    // Now here comp a and comp b are the variable of the comp structure.
    // now we will make a third comp variable in which we will store the result.
    comp c;

    // multiplying real and imagenary part individually.
    c.real = a.real*b.real - a.img*b.img;
    c.img = a.real*b.img + a.img*b.real;

    // product of complex numbers are different.
    return c; // returning a structure variable.
}


// making the main function.

void main(){

    // making two variable of comp structure.
    // initializing them at compile time.
    comp first = {3, 4};
    comp second = {5, 15};

    printf("first complex : %.2lf + %.2lfi ", first.real, first.img);
}