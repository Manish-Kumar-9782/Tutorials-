/*----------------------------DOCUMENTATION SECTION-----------------------------*/
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
					
		
		printf: this function is only used to print/display a message or data to console screen.
				To display/print the particular kind of data it need a format specifier for that kind of data type.
		
		scanf: this function is only used to read input data from the user.
				To read a particular kind of data it need a format specifier for that kind of data type.
		
		Format Specifier:
			format specifier is used to define that what kind of data will be printed on the consol and scanned
			from the user.
			
			used specifier:-
				
				%c -- to print or scan character type value.
				%d -- to print or scan integer type value.
	
*/


#include <stdio.h>


int main(){
	
	// initialization: if a vriable is assigned some value at the declaration time then it call initialization of
	// the variable.
	
	int a = 0;  // initialization variable a as 0
 	int b = 0;  // initialization variable b as 0
 	
 	
 	printf("Enter the first value: "); // Only printing the message
	 scanf("%d", &a);  // reading or scannig the input from user.
	 // scanf will read the integer as input since %d is used.
	 
	printf("Enter the second value: ");  // Only printing the message
	scanf("%d", &b);  // reading or scannig the input from user.
	// scanf will read the integer as input since %d is used.
	
	/*
		1. Now we will show the result only.
		2. Since result will be as integer data type.
		3. To show the integer type result we will use %d.
	*/
	printf("\nResult: %d", a+b);	
//	int a = 0;
	
}
