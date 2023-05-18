#include<stdio.h>

/*
	In this section we will see the implementation of four different kind of function.

	// out of the main function or any other function which is not inside the main
	function is called global scope.
	
	we can declare and define the any function at any place in globale section.
	
	there are two different kind of apporach to make/define function.
	
	1. before the main function.
	2. after the main function.
	
	we can stages of defining and using a funciton.
		1. declaring the function.
		2. defining the function.
		3. calling the funciton.
	
	1. if we want to define a function, before the main function then we need don't need
	to declare it first we can directly define the funciton.
	
	2. but if we want to define a function, after or below the main function then we need
		to first declare it before the main function. with return type, name and number of 
		parameters with types.
		
		declaration: <return_type> <name>(type1, type1, ..., typeN.);
		
	// In this section we will make four funciton for each type of function.
	
	Note: since compiler read the program in top to bottom manner, so if we don't declare the
	function before the main function while we are defining that function below the main
	function it will give us war
*/

// declaration of 1st type function -> 1. no argument, no return type.
void greeting();

// declaration of 2nd type function -> 2. arguments, no return type.
void add(int, int);

// declaration of 3rd type funciton -> 3. no arguments, return type.
float getPi();

// declaration of 4th type function -> 4. arguments, return type.
int square(int);


void main(){
	// calling the funciton greeting function.
	greeting();
	
	// calling the add function
	add(4,5);
	
	// calling the getPi  funciton
	// since getPi is returning somthing so we need to hold that value in a variable
	// to use it, in this case we will store that value inside a new variable 
	float value; // Note: our variable data type should match to functions returned 
	// valud data type.
	value = getPi(); 
	printf("value of pi: %f\n", value);
	// %f: format specifier for floating values.
	
	// square of 25
	printf("Square of 25: %d\n", square(25));	
}

// definition of 1st function
void greeting(){
	printf("-------------------------------------------\n");
	printf("\t\tHello World...!\n");
	printf("-------------------------------------------\n");
}

// definition of 2nd type function
void add(int a, int b){
	
	int c = a+b;
	printf("\nSum of %d + %d = %d\n", a,b,c);
}

// definition of 3rd type function
float getPi(){
	// Note: since our return value type if float, hense we are taking our function's 
	// return type folat also.
	return 3.14159;
}

// definition of 4th type function.
int square(int a){
	// 
	int result = a*a; // 
	return result;
}


