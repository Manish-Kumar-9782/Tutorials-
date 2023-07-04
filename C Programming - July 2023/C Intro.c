#include<stdio.h>

/* Now our entry point is main function.
 () : round barcket or paranthesis
 {}: curly bracket
 [] : square bracket
statement: it is a code continuous of single line or multi line terminated
 by semicolon.
 
 string: it is a (text message) a sequence of characters enclosed by 
 	double quotes
 	
 	Indentifier & Keyword: 
 	
 	keyword: it is predefined word which is reserved for doing special kind 
 	operation.
 	keywords: int, float, void, char, .. etc.
 	
 	void: keyword for data-type, denote no type.
 	
 	variable:  it is holder which can hold values inside it.
 	Note: a variable can only store/hold the single type of value
 	which is defined during declaration of variable.
 	
 	declaration of variable;
 	
 	data-type variable;
 	
 	our main data type: int, float, char, double, void.
 	modifers: short, long
 	
 	for number: int, float, double.
 	character: char.
 	
 	format specifier: it is used to specify that what kind of value
 	we are going to print.
 	
 	int: %d, float: %f, char: %c, double: %lf
 	
 	\n: newline character, it is used to create new line inside the string.
*/

void main(){
	// here 'main' & 'printf' are both identifier
	printf("Hello world \n");
	
	int Integer_number; // declaring a variable named as Integer_variable
	
	// assingning a value to Integer_number variable.
	Integer_number = 1335;
	
	printf("%d",Integer_number);
}
