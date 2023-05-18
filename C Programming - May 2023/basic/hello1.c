#include<stdio.h>

// data-type: int, float, double, char

// int: whole number  (1,2,3)
// float , double --> decimal number (point numbers 4.31)
// char --> character '1', 'a', '/'

/*
	keyword and identifier: 
	
	block, function, structure, typdef alias type
	
	int var_name; <int: keyword> <var_name:identifier>
	
	variable name convention:
	1name : not allowed
	my name: not allowed
	my_name: allowed
	name1: allowed
	int : not allowed
	
	syntax: <data-type> <variable_name>;  // declaration of variable
	// initialize the varible
	int my_var;
		
	String: simple text message.
	
	\n: newline character (escape sequence)
*/

void main(){
	
	int int_value=200;  // whole number %d
	// Note: if we don't initialize any value to variable then it will 
	// assign random value to variable. 
	printf("int_value : %d\n",int_value);
	int_value = 10; // assigning new value
	float float_value;  // point decimal numbers %f
	
	printf("int_value : %d\n",int_value);
	
	printf("float_value : %f\n",float_value);
	
}
