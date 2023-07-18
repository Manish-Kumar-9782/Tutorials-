#include<stdio.h>

/*
    return-type function-name (parameter_list){
        // function body block

        return value;
    }

    parameter: identifier (variable) declared during defining the function inside the
        parameter list.

    argument: it is the value of the parameter during call of the function..

    1. function with no argument and no return type.
    2. function with no argument but with return type.
    3. function with argument but no return type.
    4. function with argument and return type.
*/


// function with no argument and no return type
void greeting();

// function with no argument but with return type.
float getPI();


void main(){

    // calling the greeting function.
    greeting();

    // calling the getPI function.
    float pi = getPI();
    printf("The value PI: %f\n", pi);

}

// defining the function
void greeting(){
    printf("Hello, Good Morning, i hope this will be fun...!!\n");
}

float getPI(){
    float value = 3.14159;
    return value;
}

