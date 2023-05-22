#include<stdio.h>

/*
*	int a;
*	bool isAlive; --> true, false2
*	int isAlive: ---> 1, 0
* 
	Operators:
		1. arithmetic Operators +, -, /, *, %
		2. assignment Operators =, +=, -=, /=, *= %=  (returns new value)
		3. Relational Operators < , > , <=, >=, ==  
				(always test left value with right one) --> true(1)|false(0)
		4. Logical Operators &&(AND) , ||(OR) , !(NOT)
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
	{
		printf("\n========================Arithmetic Operators =====================\n");
		printf("adding a and b: %d\n", result);
		printf("subtracting a and b: %d\n", a - b);  // a-b expression
		printf("Multiply a and b: %d\n", a * b);  // a-b expression
		printf("dividing a and b: %d\n", a / b);  // a-b expression
		printf("dividing b and a: %f\n", (float)b / a);  // a-b expression
		printf("dividing 7/10 : %f\n", (float)7 / 10); // 

		// --> 7/10 --> 0.7 float 7(int)/10(int) ---> (0)int ---> 0.00000
		// --> 7/10 --> 0.7 float 7(float)/10(int) ---> (0)int ---> 0.00000

		printf("\n========================Arithmetic Operators End=====================\n\n");
	}


	{
		printf("\n========================Assignment Operators =====================\n");
		printf("a: %d  b: %d\n", a, b);
		printf("adding a and b: %d\n", a + b); // neither a or b will update its value.
		// to update we can write the expression.
		// to update a: a = a + value  -- > a += value
		// to update b: b = b + value  -- > b += value
		 // a-b expression

		int value = 7;
		printf("add and assignment operator a+=%d ==> %d\n", value, a += value);
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


	{
		printf("\n========================Relational Operators=====================\n");
		printf("a: %d, b: %d, x: %d\n", a, b, x);
		printf("a < b: %d\n", a < b);
		printf("a > b: %d\n", a > b);
		printf("x <= b: %d\n", x <= b);
		printf("b >= a: %d\n", b >= a);

		printf("\n========================Relational Operators Ends=====================\n\n");
	}

	
	{
		printf("\n========================Logical Operators=====================\n");
		printf("a: %d, b: %d, x: %d\n", a, b, x);
		// Logical Operators: 
		// true && false --> false  expression && expression
		// false && false --> false  
		// false && true --> false 
		// true && true --> true  
		// && , || --> binary

		printf("a < b and a > x: %d\n", a < b && a > x);
		printf("b > a or a > x: %d\n", b > a || a > x);

		// ! not Operator --> unary operator  true --> false, false ---> true
		printf("not a > x: %d\n", !(a > x));


		printf("\n========================Logical Operators Ends=====================\n\n");
	}

	{
		printf("\n========================Increment Operators=====================\n");
		printf("a: %d, b: %d, x: %d\n", a, b, x);

		printf("Increment Operator (a++) on a : %d\n", a++);
		printf("after increment a is : %d\n", a);
		// a++ : first execute the statement then 
		// performs increment operation and return the value (execute first then return)

		printf("Increment Operator (++a) on a : %d\n", ++a);
		printf("after increment a is : %d\n", a);
		// ++a : first perform the increment operation and return the value then execute the statement

		printf("decrement Operator (a--) on a : %d\n", a--);
		printf("after decrement a is : %d\n", a);
		// a++ : first execute the statement then 
		// performs increment operation and return the value (execute first then return)

		printf("decrement Operator (--a) on a : %d\n", --a);
		printf("after decrement a is : %d\n", a);

		printf("\n========================Decrement Operators Ends=====================\n\n");
	}
}