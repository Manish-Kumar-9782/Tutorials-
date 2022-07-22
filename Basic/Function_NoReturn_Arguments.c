/*----------------------Documentation Section-----------------*/
/*
	Program: <<< NoReturn type but Arguments >>>
	
	IN this section we will see how declare and define the NoReturn Type but having argument
	type function and their usage
	
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

// here we will make an add funciton to add int float, double 
// these function will not return any thing, instead they will show the result.

// add two integer 
void add_integer(int, int);

// add two float
void add_float(float, float);

// add two double
void add_double(double, double);

// add int and float
void add_int_float(int, float);

// add int double 
void add_int_double(int, double);

// Note: any function can have various type of argument and it's return type may have user-defined.

/*---------------------------------------------------------------------------*/

void main(){
	
	// calling add_integers
	add_integer(2,3);
	add_integer(10,22);
	
	// calling add_float
	add_float(2.4, 5.6);
	
	// calling add_double
	add_double(34.5, 565.6);
	
	// calling add_int_float 
	add_int_float(345, 456.69);
	
	// calling add_int_double
	add_int_double(3563, 4646.565);
}


/*--------------------------Sub section contain sub function--------------------*/

// add two integer 
void add_integer(int a, int b){
	printf("add of a and b: %d+%d = %d\n", a,b, a+b);
}

// add two float
void add_float(float a, float b){
	printf("add float of a and b: %f + %f = %f\n", a, b, a+b);
}

// add two double
void add_double(double a, double b){
	printf("add double of a and b: %lf + %lf = %lf\n", a, b, a+b);
}

// add int and float
void add_int_float(int a, float b){
	printf("add int and float of a and b: %d + %f = %f\n", a, b, a+b);
}

// add in and double
void add_int_double(int a, double b){
	printf("add int and double of a and b: %d + %lf = %lf\n", a, b, a+b);
}
/*---------------------------------------------------------------------------*/
