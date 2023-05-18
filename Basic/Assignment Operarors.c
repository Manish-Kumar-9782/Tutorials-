#include<stdio.h>

// assignment operators are used to perform some expression and 
// after that assign the left value to the right variable.

/*
	1. = : simple Assignment.
	2. +=: first add then assign.
	3. -=: first subtract then assign.
	4. /=: first divide then assign.
	5. *=: first multiple then assign.
	6. %=: first get modulus then assign.
	
	x += 10; ------> x = x + 10;

*/

void main(){
	
	int a; 
	// to make variable first define the datatype and then define the variable
	// Name
	// <datatype> <variableName>; declaration of an identifier.
	
	int b = 20; // declare and initializing the b.
	a = 20; // assigning 20 to a.
	
	printf("resutl of a + b: %d\n", a+b);
	// Now we will also print a and b to show that, they are changed or 
	// not after taking participate in the a+b operation.
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	// our a and b does not chnage.
	
	printf("updating a by 10\n");
	a+=10; // a = a + 10
	printf("after adding 10 to a: %d\n", a);
	
}
