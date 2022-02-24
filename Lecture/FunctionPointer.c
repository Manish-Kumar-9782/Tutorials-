/* As normal pointer which contains the address of normal data types like int, float, double we
    have another kind of function which is called function pointer.

    Function Pointer: Function pointer is a pointer which contains the address of a function. Declaration syntax 
        of a function points as given:

        data-type (* func_ptr)(arguments data type) = &func  // address of function.
*/

#include<stdio.h>

// Now we will make a function which will print some kind of message.

void message(){
    printf("\n\nHello world\n");
}

int sum(int a, int b){
    return a+b;
}

int square(int a){
    return a*a;
}

// Now we have three funcions and we will call all of then by using function pointers.

void main(){

    void (* func1)() = message;  // passing the message function address
    int (* func2)(int , int) = sum; // passing the sum function address
    int (* func3)(int) = square; // passing the square function address.

    // Now we will call all three function through pointer variable and also we will inspect their result.

    int sum_result = func2(2,3); // func2 points to the sum function.
    int square_result = func3(5); // func3 points to the square function.


    // Now we will inspect all the result.

    // 1. calling message function throught func1 pointer.
    func1();

    // 2. checking the result of sum function which is called by using func2.
    printf("\nResult of sum function accessed by func2: %d\n", sum_result);

    // 3. checking the result of square function which is called by using func3.
    printf("\nResult of square function accessed by func3: %d\n", square_result);

}