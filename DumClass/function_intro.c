#include<stdio.h>

/*
	function syntax:
		<return-type> <functon-name>(parameter_list){
			// statements of function body
			return value
			// we can only return a single value at time.
		}

	// 1. no-return, no argument
	// 2. no-return but argument
	// 3. return but no argument
	// 4. return and argument.
*/

// 1. no-return and no-argument
void greeting() {
	printf("Hello how are you?");
}

//====================================================//
void main() {

	greeting();
	isAdult(12);
	
}
//====================================================//

// take an age number and tell that you are an adult.
void isAdult(int age) {
	if (age > 18) {
		printf("You are an adult..!");
	}
	else {
		printf("You are not an adult..! Come after few years later....");
	}
}
