// In this section we will see double pointer concept in which we points to another pointer.

/*Double Pointer: Double pointer is another special kind of variable and pointer which store a single level pointer address. 

For example: Suppose that we have three variable. a, *b, **c.

-> Then pointer b can hold the address of the a variable.
-> But pointer c can only hold address of a single level variable in this case variable b is a single level pointer.
    So, in this case pointer c will or can hold pointer b address. */

#include<stdio.h>

void main(){

    // Now we will make three varible and we will see that how a double pointer is usefull.

    int a=10; // declaring a int varialble.
    int *b = &a; // declaring the one level pointer and assign it address of a variable.
    int **c = &b; // declaring the double pointer (or two level pointer) which only can hold a pointer address.
    // since a and b are holding the address of another variable or pointer so we need to use %x or %p for address format specifier.
    printf("\nValue of a: %d ", a);
    printf("\nValue of b: %x", b);  
     
    printf("\nValue of c: %x", c);


    printf("\nHere %x is the address of variable a and %x is the address of pointer b.", b, c);


    // Note: we can access variable a value by using both pointers in this way.
    printf("\n\nValue of a by using pointer b: %d", *b);
    printf("\nValue of a by using pointer c: %d", **c);

}