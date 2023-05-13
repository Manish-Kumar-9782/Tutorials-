#include<stdio.h>

/*
*	function header:
*		<return-type> functionName(parameter list){
	// function body
}

1. no return type, no argument/parameter

2. no return type, but argument

3. return type but no argument

4. return type and argument

	we must follow these three steps to define a function.

	1. declaration of the function.
	2. defining the function.
	3. calling the function. functionName();

	we must declare the function:
		1. if our function definition below the main function. in that condition
			we must declare the function before the main function.
		2. if our function is not defined in currently working file.
			we must declare the function declaration in a header file.
			and define that function in a source code file.
* 
*/

// Now we are going to define a function
// no return type and no argument.
void hey() {
	printf("hello Bhaya kese ho...!\n");
}


void isAdult(int age);  // no-return type but argument
int ageRestriction(); // return type but no argument
int add(int a, int b); 

// void return type: don't returning anything
void main() {

	hey(); // calling hey function 
	isAdult(13);
	isAdult(19);

	int age = ageRestriction();
	printf("Restricted Age: %d", age);

	printf("sum of %d + %d = %d", 10, 20, add(10, 20));
	// return
	//return value;
}


// no return type but argument;
void isAdult(int age) {
	if (age > 18) {
		printf("You are an adult: Access granted..!\n");
	}
	else {
		printf("You are not an adult: Access Denied..!\n");
	}
}

int ageRestriction() {

	return 35;
}

int add(int a, int b) {
	return a + b;
}