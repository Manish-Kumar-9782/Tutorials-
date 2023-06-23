#include<stdio.h>
/*
	Control Statement:
		if-else statement: 
			expression

		switch statement:
			constant value 

	syntax:
		if (condition/expression){
			// block for 'if' statement
			// in this we writes statements to be executed when 
			// condition satisfies.
		}

	yes or no type statement

	if(condition){

		// yes statement
	}
	else{
		// no statement
		// else statement will run surly, if 'if' statement does  not run.
	}


	// multiple if else statement
	if (condition1){
		// statement 1
	}
	else if(condition2){
		// statement 2
	}
	else if(condition 3){
		// statement 3
	}
	else{
		// final statement
	}
*/
void main() {

	// creating some variable
	int a = 30;
	int b = 20;
	int c = 10;


	if (a > b) {
		// this will run only, when a>b is true.
		printf("a is greater than b\n");
	}

	if (a < b) {
		printf("a is less than b\n");
	}


	// updating above code into the if-else statement
	if (a < b) {
		printf("a is less than b\n");
	}
	else {
		printf("either a is greater than b or a is equal to b\n");
	}


	if (a > b) {
		printf("a is greater than b\n");
	}
	else {
		printf("either a is less than b or a is equal to b\n");
	}


	// multiple if else statement 
	// greater, less, equal
	a = 20;
	if (a > b) {
		printf("a is greater than b\n");
	}
	else if (a < b) {
		printf("a is less than b\n");
	}
	else {
		printf("a is equal to b\n");
	}

}