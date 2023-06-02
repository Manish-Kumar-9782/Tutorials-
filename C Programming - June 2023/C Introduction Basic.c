#include<stdio.h>
// stdio.h is header file.
// header file: it is a file which contians functions and variable declarations.
// in stdio.h header file we have standard input output operation related declaration.

// data types: int, float, double, char
// operators: +,-,=,/,%,==,<=,<,>,>=,&&, || etc.
// \n: it is escape sequnce character (newline character), it is used to create new line

// string: a sequence of character, 
// literal string: a string wrapped inside the pair of double quote ("").
// msvc, c99, c11, c17, c23

/*
	Keyword ans identifier:

	keyword: words in c those have specific menaning and operation.
		example: void, for, if, int, float, double, char.

	identifier: it is a name of a varaible, a function, a unione, type alias name, structure name.

	
	variable: <data-type> <variableName-identifier>;
*/



void main() {

	int myNumber = 10;
	int yourNumber = 15;
	printf("hello world!              bye bye///");
	printf("\nMy name is Hitesh\n");

	int diff = myNumber - yourNumber;
	printf("difference in b/w the myNumber and yourNumber: %d", diff);
}