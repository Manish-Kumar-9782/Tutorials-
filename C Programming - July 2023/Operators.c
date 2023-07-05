#include<stdio.h>

/* 
Operators: Operators are symbols/ special character which perfrom
special kind of operation.

	1. Arithmetic Operators: +, -, /, *, %
	2. Relational/ Comparison Opeartors: <, > <=, >=, ==, !=
	3. Assignment Operators: =, +=, -=, *=, /=, %=
	4. Logial Operators: &&, ||, !
	5. increment & decrement Operator: ++, --
	6. Ternary Operator: ? :
	7. bitwise operators:  
	
	boolean values:
		0: false
		1: true
		
	type casting:
		implicit type casting: automatically
		explicit type casting: manually	

*/

void main(){
	
	int a = 10;
	int b = 54;
	int c = 76;
	
	printf("\n============= Arithmetic Operator =============\n");
	printf("a: %d, b: %d, c: %d\n", a,b,c);
	printf("sum of a + b: %d\n", a+b);
	printf("subtract a from b: %d\n", a-b);
	printf("mutliply of a * b: %d\n", a*b);
	
	// becareful here
	printf("dividing a from b: %d\n", a/b);
	printf("dividing b from a: %d\n", b/a);
	printf("dividing b from a: %f\n", (float)b/a);		
}
