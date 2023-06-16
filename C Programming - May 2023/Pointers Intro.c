#include<stdio.h>


/*
	Pointers: Pointers are special kind of variable which holds the memory address of the other variable.
	Note: it does not hold the value of the variable but we can access it.

	<data-type> *<variable-name>;

	reference operator: &variable  --> memory address of that variable
*/

void main() {

	int a = 10;
	int b = 20;

	// our pointer
	int *ptr = NULL; // Initializing our pointer as null value

	// assigning the address of variable a.
	ptr = &a;


	printf("value of variable a: %d\n", a);
	printf("Address of variable a: %p\n", &a);

	printf("value of variable ptr: %p\n", ptr);
	printf("value at address hold by ptr: %d\n", *ptr);

	// Now changing the value of variable a.
	*ptr = 20;

	printf("after changing Value of a Now: %d\n", a);


	// Now creating a new array with the help of the pointer

	int* array = (int)malloc(sizeof(int)*6);
}
