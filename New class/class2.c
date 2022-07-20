/*----------------------------------DOCUMENTATION SECTION----------------------------------*/
	/*
	
		In this section we will discuss about the basic things of the c program.
		
function: function is a set of instruction in which mutiple line of statement(instruction) are defined.
				these instruction can be executed by calling the function by it's name.
		
global declaration area: it is the area (memory area) outside the every function including main funtion
			in which we declare those variable or function, that can be accessed by any function.
		
int: it is a keyword used to store the integer type values (whole numbers).
		
float: it is a keyword used to store the decimal type values (deciaml values like 1.24, 3.14).
		
char: it is keyword used to store the character value in a variable.
		
const: it is a keyword used to define a variable as constant variable, that can be initialized only once.
				const variable value cannot be changed.
		
void: void is used to define the return type of the function.
		
return type: if a function return a something to the caller function then the value must be return in 
					specified data type, that type is called return type.
					
		
Format Specifier:
		format specifier is used to define that what kind of data will be printed on the consol and scanned
		from the user.
			
			used specifier:-
				
				%c -- to print or scan character type value.
				%d -- to print or scan integer type value.
		
		
	subfunctions:
			
		These subfunctions declaration is given in the global declaration seciton.
		Note: if we don't give the declaration of these function in the global decleration then compiler
			will give you an error of undeclaration.
			
		1. void komal(): 
		2. void saloni(): 
	
	*/
/*-----------------------------------------------------------------------------------------*/

/*----------------------------------LINKING SECTION----------------------------------*/
#include <stdio.h>
/*-----------------------------------------------------------------------------------------*/

/*----------------------------------DEFINATION SECTION----------------------------------*/
#define MAX 100
/*---------------------------------------------------------------------------------------*/

/*----------------------------------GLOBAL DECLARATION SECTION----------------------------------*/

char a = 'a';  // a variable to store the character type 

void komal(); // a declaration of the function named as komal
void saloni();  // a declaration of the function named as saloni

/*---------------------------------------------------------------------------------------------*/



/*----------------------------------MAIN FUNCTION SECTION--------------------------------------*/

void main(){
	
	const float pi = 3.14159;  // initializing const variable.
	// A float type variable which is made constant
	// now its value cannot be changed.
	
	int b = 10;  // initializing integer b.
	// an interger type variable to hold the integer type data.
	
	printf("value of a: %c\n", a);
	// printing the value of character variable a by using %c.	

	printf("value of a: %d\n", b);	
	// printing the value of the integer variable a by using %d.
	
	saloni(); // calling saloni function.
	
	// Note: Here caller is the main function.
	// caller: means which is calling the another function.

//	printf("value of b: %d", b);
//	printf("value of value1: %d", value1);  ---> // accessing non-global to main
//	printf("value of value2: %d", value2); --> // accessing non-global to main
	
}

//-------------------------------------------------------------------------------------------------//

/*----------------------------------SUB FUNCTION SECTION--------------------------------------*/
void komal(){
	// this komal function will create a scope/area (in memory) for komal function.
	int value1 = 10;
	printf("Hello  Komal\n");
}

void saloni(){
	// this saloni function will create a scope/area (in memory) for saloni funciton.
	int value2 = 20;
	printf("Hell saloni\n");
}

/*
	Since: both komal and saloni have their own individual scope, 
		1. value1 cannot be used in main and saloni function.
		2. value2 cannot be used in the main and komal function.
		
	Note: only a global variable will be accessible in all the function.
*/

/*----------------------------------------------------*/
