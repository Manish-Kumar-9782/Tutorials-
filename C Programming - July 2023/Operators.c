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

void main() {

	int a = 10;
	int b = 54;
	int c = 76;
	int d = 10;

	printf("\n============= Arithmetic Operator =============\n");
	printf("a: %d, b: %d, c: %d\n", a, b, c);
	printf("sum of a + b: %d\n", a + b);
	printf("subtract a from b: %d\n", a - b);
	printf("mutliply of a * b: %d\n", a * b);

	// becareful here
	printf("dividing a from b: %d\n", a / b);
	printf("dividing b from a: %d\n", b / a);
	printf("dividing b from a: %f\n", (float)b / a);


	printf("\n============= Compairson Operator =============\n");
	printf("a: %d, b: %d, c: %d  d: %d\n", a, b, c, d);
	printf("is a greater than b: %d\n", a > b);
	printf("is a less than b: %d\n", a < b);

	// test <= and >= operator
	printf("is b greater than or equal to c: %d\n", b >= c);
	printf("is b less than or equal to c: %d\n", b <= c);

	// testing <= and >= Operator
	printf("is a greater than or equal to d: %d\n", a >= d);
	printf("is a less than or equal to d: %d\n", a <= d);

	// testing == and != operator
	printf("is a equal to b: %d\n", a == b);
	printf("is a equal to b: %d\n", a != b);

	printf("\n============= Assignment Operator =============\n");
	printf("a: %d, b: %d, c: %d  d: %d\n", a, b, c, d);

	// += : add and assignment operator
	// variable += value; --> variable = variable + value;
	// a += 10; --> a = a + 10
	// a -= 10; --> a = a - 10

	printf("increasing a by 10: %d\n", a += 10); // a+b ; a = a+10 --> a+=10
	printf("now our a is: %d\n", a);
	printf("decresing a by 10: %d\n", a -= 10);
	printf("now our a is: %d\n", a);


	system("cls");
	// Increment & Decrement Operator
	printf("\n============= Increment/Decrement Operator =============\n");
	printf("a: %d, b: %d, c: %d  d: %d\n", a, b, c, d);

	// prefix increment : ++a;
	// suffix increment : a++;
	printf("prefix Incrementing a: %d\n", a++);
	printf("a is: %d\n", a);

	printf("suffix Incrementing a: %d\n", ++a);
	printf("a is: %d\n\n", a);

	printf("prefix Decrementing a: %d\n", a--);
	printf("a is: %d\n", a);

	printf("suffix Decrementing a: %d\n", --a);
	printf("a is: %d\n", a);

}
