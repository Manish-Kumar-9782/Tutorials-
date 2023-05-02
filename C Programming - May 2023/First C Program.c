#include<stdio.h>

/*
	1. scope --> global scope, local scope.
	
	2. syntax: --> grammer of language.
		-> keyword, indentifier  --> both are names or words
	
	3. variable --> indentifier.
		
		-> syntax: data-type  var-name;
		
		, `, ~ , !, @, #, $, %, ^, *  are not allowed in variable name
		--> allowed on name: with no space
		
		my var --> X not allowed
		myvar --> allowed
		my_var --> allowed
		1my_var --> X not allowed
		my_var1 --> allowed
		
		data-Types: all are keywords
			--> int,float, double, char
				--> int --- 1, 2,3,4,5,6
				--> float --- 3.412, 5.65
				--> double --- 5.67,4.46
				--> char -- 'a','b', 'c'
		
*/

void main(){
	int my_var1;  // variable declaration
	// assignment operation, assigning int-type value to my_var1
	my_var1 = 15;
	printf("Hello world..."); 
	// printf(my_var1);
	// printf("%d",var)
	printf("%d",my_var1);
}
	
