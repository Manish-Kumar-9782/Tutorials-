#include<stdio.h>

/*
	Operators
		1. Arithmetic Operators
			+, -, / ,*, %

		2. assignment operators
			=, +=, -=, /=, *=, %=

		3. Comparison Operator
			== (equality Operator), 
			!= (Not Equal Operator), 
			<= (less than or equal to), 
			>= (greater than or equal to), 
			<  (less than operator), 
			>  (greater than operator)

		4. Logical Operators
			&&, ||, !

		5. Ternary Operator ? : 

		6. sizeof operator,

		7. address reference operator &

		8. Bitwise Operator
			>>, <<, &, |

		9. Increment and Decrement Operator 
			++, --
	
		type Casting: 
			implicit type casting --> lower data type to higher data type (primitive data type)
			explicit type casting --> 

		bool: true (1), false (0)	
	*/

void main() {

	// Arithmetic Operator

	/*
		\n : newline character, to create new line.
	*/

	int a = 30; // initialization of variable a
	int b = 50;
	int c = 20;
	int d = 30;

	printf("==================== Arithmetic Operator ====================\n");

	printf("a: %d, b: %d\n",a,b);
	printf("adding a and b: %d\n", a + b);
	printf("subtracting a and b: %d\n", a - b);
	printf("multiplying a and b: %d\n", a * b);

	printf("dividing a and b: %d\n", (float)a/b);
	// Note: since a/b or b/a giving point values so those values can't be stored inside the 
	// integer type variable, neither we can represent them by using the %d format specifier

	// for that use only %f (float) %lf (double)
	printf("dividing a and b: %f (float)\n", (float)a/b);
	


	// modulus operator to get the remainder 

	printf("modulus a %% b: %d \n", a % b);
	printf("modulus b %% a: %d \n", b % a);

	printf("\n\n=============================================================\n\n");

	printf("==================== Assignment Operators ====================\n");
	printf("a: %d, b: %d\n", a, b);
	// adding and assignment operator --> +=
	// if we want to update our a with a+x result
	// a = a + x; -> now a is updated by +x value.
	// a += x  --> a  = a+x;
	printf("updating a with +10: %d\n", a += 10);
	printf("updating a with -30: %d\n", a -= 30);


	printf("\n\na: %d, b: %d\n", a, b);
	printf("=============================================================\n");
	


	printf("\n\n==================== Relational/Comparison Operator====================\n");
	c += 10;
	printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);

	printf("is a > b: %d \n", a > b);
	printf("is a < b: %d \n", a < b);

	// comparing that c is greater than d or equal to d
	printf("is c > d or c == d: %d\n", c >= d);
	printf("is a > d or a == d: %d\n", a >= d);

	// comparing that a or b equal 
	printf("is a == b: %d\n", a == b);

	// comparing that a is not equal to b;
	printf("is a not equal to b: %d\n", a != b);
	printf("\n\n=============================================================\n");

	printf("\n\n==================== Logical Operator ====================\n");
	// && and || are binary operators
	// ! is a unary operator

	// <expression> && <expression> --> boolean result
	// <expression> || <expression> --> boolean result
	// !<expression> --> boolean result

	/*
		&& AND Operator

		true && true --> true
		true && false --> false
		false && true --> false
		false && false --> false

		|| OR OPerator

		true || true --> true
		true || false --> true
		false || true --> true
		false || false --> false

		! NOT Operator

		!true ---> false
		!false ---> true
	*/
	printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);

	printf("is b greater than a AND less than c: ");
	printf("%d && %d ---> %d\n", b > a, b<c, b>a && b < c);

	printf("is c greater than a AND less than b: ");
	printf("%d && %d ---> %d\n", c > a, c < b, c>a&& c < b);

	printf("\n\n=============================================================\n");
}