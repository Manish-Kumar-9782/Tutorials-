#include<stdio.h>

/*
	Operators:
		1. arithmetic Operators +, -, /, *, %
		2. assignment Operators =, +=, -=, /=, *= %=
		3. Relational Operators < , > , <=, >=, ==
		4. Logical Operators && , || , !
		5. Increment/Decrement Operators ++, --
		6. bitwise Operators ?:


		explicit Type casting:
			(data-type)<value>
			 
		implicit type casting:
			lower to higher data type.
*/

void main() {

	int x = 10; // assignment Operator used
	int a = 20, b = 10; //  inline multiple variable declaration & initialization.
	int result = a + b; // declaration of result, a+b addition operation, assignment operation
	// of resulted value.
	printf("\n========================Arithmetic Operators =====================\n");
	printf("adding a and b: %d\n", result);
	printf("subtracting a and b: %d\n", a-b);  // a-b expression
	printf("Multiply a and b: %d\n", a*b);  // a-b expression
	printf("dividing a and b: %d\n", a/b);  // a-b expression
	printf("dividing b and a: %f\n", (float)b/a);  // a-b expression
	printf("\n========================Arithmetic Operators End=====================\n\n");


	printf("\n========================Assignment Operators =====================\n");
	printf("a: %d  b: %d\n",a,b);
	printf("adding a and b: %d", a + b); // neither a or b will update its value.
	// to update we can write the expression.
	// to update a: a = a + value  -- > a += value
	// to update b: b = b + value  -- > b += value
	 // a-b expression

	int value = 7;
	printf("add and assignment operator a+=%d ==> %d\n", value, a+=value);
	printf("value of a after update: %d\n", a);

	value = 10;
	printf("add and assignment operator a-=%d ==> %d\n", value, a -= value);
	printf("value of a after update: %d\n", a);

	value = 7;
	printf("add and assignment operator a/=%d ==> %d\n", value, a /= value);
	printf("value of a after update: %d\n", a);

	value = 13;
	printf("add and assignment operator a*=%d ==> %d\n", value, a *= value);
	printf("value of a after update: %d\n", a);

	value = 7;
	printf("add and assignment operator a%%=%d ==> %d\n", value, a %= value);
	printf("value of a after update: %d\n", a);
	printf("\n========================Assignment Operators End=====================\n\n");

}