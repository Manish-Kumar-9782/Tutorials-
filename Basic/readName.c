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
	
	
	char ch = ' ';  // initializing the character type variable ch as ' ' (blank space).
	
	printf("Enter your name: ");  // Only printing the message.
	
	scanf("%c", &ch);  // reading the first character of the input
	//Note: scanf will read only one one character at a time due to using %c.
	printf("Hello %c", ch);
	// printing the ch value which is readed/scanned by the scanf function.
	
	/*
		Now we need to read all the remaing character.
		-> for that we wil use the while loop.
		-> below while loop will run until we don't press (hit) Enter.
	*/
	
	while(ch != '\r'){ 
	
		// meaning of "ch != '\r'" 
		// run the while loop until we don't press the Enter whose special character value is '\r'.
		
		// read every character 
		scanf("%c", &ch);
		// print every character scanned/readed by the scanf function.
		printf("%c", ch);
	}
	
	// Now we will read all the character of the name.
}
