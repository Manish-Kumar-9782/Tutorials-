/*----------------------Documentation Section-----------------*/
/*
	Program: In this section we will see about function and its parts.
	
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

#include<stdio.h>

/*------------------------Global Declaration Section-------------------------/
// Now we will make two function func1 and fun2
/*
	1. func1 will be first declared in global section and it will be defined in subsection below main fucntion.
	2. func2 will be defined in global section.
*/


// declaration of func1
void func1(); // Note: here we must place the semicolon to declare the function.


// defination of func2
void func2(){
	// since this is void function so it will not return anything.
	// therfor no need to mention the return value.
	
	printf("Hello func2\n");
}

/*---------------------------------------------------------------------------*/

void main(){
	
	// Now here we will call the func1 and func2.
	// In this case main function will be the caller of func1 and func2
	// func1 and func2 will be called callie.
	
	func1(); 
	func2();
	
}


/*--------------------------Sub section contain sub function--------------------*/

void func1(){
	// since this is void function so it will not return anything.
	// therfor no need to mention the return value.
	printf("Hello func1\n");
}

/*---------------------------------------------------------------------------*/
