#include<stdio.h>

/*
	Relational Operator:
	
	1. < 	: less than operator.
	2. > 	: greater than operator.
	3. <= 	: less than or equal to operator.
	4. >= 	: greater than or  equal to operator.
	5. ==	: equal to operator.
	6. !=	: not equal to operator.
	
	Relational operator are used to compare value in b/w the two same 
	kind of data type. 
	
	Note: Relational Operator return/gives boolean values, true or false.
	
	since we don't have any repersentation of boolean value in c, so it use
	1 as true, and 0 as false.
*/

void main(){
	
	// Now we will declare and assing two variables.
	int a, b, c; // inline declaration of mutliple varaible.
	
	a = 10;
	b = 20; 
	c = 10;
	
	printf("a = %d, b = %d, c = %d\n", a,b,c);
	
	// now we are going to compare, a and b.
	
	// is,	a is less than b.
	// is,  a is greater than b.
	
	printf("is, is a less than b: %d\n", a<b); 
	printf("is, is a greater than b: %d\n", a>b);
	printf("is, is a less or equal than b: %d\n", a<=b); 
	printf("is, is a greater or equal than b: %d\n", a>=b);
	
	// Note it in less/greater or equl operator we test both condition
	// if any of them is true  we will get 1.
	// if both of them is false we will get 0.
	
	// Now we will test our == : equal equal operator.
	printf("is, a equal to b: %d\n", a==b); 
	printf("is, a equal to c: %d\n", a==c);
	
	// Now we will test our != : not equal operator.
	printf("is, a not equal to b: %d\n", a!=b);
	printf("is, a not equal to c: %d\n", a!=c);
	
}
