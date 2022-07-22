/*----------------------Documentation Section-----------------*/
/*
	Program: In this section we will about different kind of function and their declaration.
	
	Function Header: return-type <function name> parameter list;
	function body: {
	
		// statements:
		return value.
	}
	
	function to add two number:
	
	int add(int a, int b){
	
		// statement
		int c = a + b;
		
		return c
	}
	
	Rule while declaring or defining a function:
	
	* if a function does not return any thing then its return type must be void.
	* if a function does return a value then it must maintain same return type on header section.
	* Naming Convention: function name should be in lower case
	* if funciton name contain multiple name add two value then we must add _ in b/w them liek add_two_value.
	* space is not allowed in two name while defining any kind indentifier.
	* we must provid the data type and identifier name in parameter list during function defination.
	
	
	Declaration of a function:
	
	Note: all the function must declared in the global section.
	
	Note2: we can define them in global section as well as in subsection, which is below the main function.
	
	Note3: if we define the function in global section then we don't need to declare it. but
	if we want to define the function in subsection then we must declare it firs in global section.
*/


/*
	Types of Funcitons:
	
	1. No return type no argument.
	2. No return type but arguments.
	3. Return type but no argument.
	4. Return type and arguments.
	
	
	1. No return type no argument:
	
		--> it does not return any value so return type void.
		--> it does not have any arguments so parameter list will be empty.
		
	2. No return type but arguments:
			
		--> it does not return any value so return type void.
		--> it does have some arguments so parameter list will contain type of argument with identifiers.

	3. Return type but no argument:
	
		--> it does have return any value so return type will be according to the return value.
		--> it does not have any arguments so parameter list will be empty.
	
	4. Return type and arguments:
	
		--> it does have return any value so return type will be according to the return value.
		--> it does have some arguments so parameter list will contain type of argument with identifiers.
*/

#include<stdio.h>

/*------------------------Global Declaration Section-------------------------*/
// Now we will declare each type of function.

//1. No rturn type no arguments

void noReturn_noArgument();

// 2. No return type but arguments.
void noReturn_Arguments(int, float, char);

// 3. Return type No Arguments.
int Return_noArguments1();  // it will return int type value
float Return_noArguments2(); // it will return float type value.
char Return_noArguments3(); // it will return char type vlaue.
bool Return_noArguments4(); // it will return either true or false
double Return_noArguments5(); // it will return either true or false

// 4. Return type With Arguments
int Return_noArguments1(int, float, char);  // it will return int type value
float Return_noArguments2(int, float, char); // it will return float type value.
char Return_noArguments3(int, float, char); // it will return char type vlaue.
bool Return_noArguments4(int, float, char); // it will return either true or false
double Return_noArguments5(int, float, char); // it will return either true or false

// Note: any function can have various type of argument and it's return type may have user-defined.

/*---------------------------------------------------------------------------*/

void main(){
	
	// Nothing here
	
}


/*--------------------------Sub section contain sub function--------------------*/


/*---------------------------------------------------------------------------*/
