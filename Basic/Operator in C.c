#include<stdio.h>

// Single line comment.

// multi line comment.

/*
In this section we will learn operators in C.

	1. Arithmatic Operators..
	2. Assignment Operator.
	3. Logical Operaotrs.
	4. Relational Operators.
	
	
	=> Arithmatic operators:
	
	+: plus operator.
	-: minus operator.
	/: divide operator.
	*: multiply operator.
	%: modulus operator.
	
	// all operator comes in binary operator.
	
	all of these operator use rvalue and lvalue.
	
	
	(): paranthesis.
	{}: curly brackets.
	[]: square brackets.
	
*/


void main(){
	
	int a = 10;
	int b = 20;
	
	char ch1 = 'a';
	char ch2 = 'b';
	
	int c = a+b; // here we  are adding a and b with plus operator.
	// result of a+b will be assigned to variable c.
	printf("result c: %d\n", c);
	
	// %d (format specifier) is used to define the format of data type as integer.
	
	// Now add ch1 and ch2.
	
	char ch3 = ch1 + ch2;
	printf("result ch3: %c", ch3);
}
