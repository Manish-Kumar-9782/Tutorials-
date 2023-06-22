#include<stdio.h>

/*
	conditional statement:

	// single condition.
	if(condition){
		// body block of if statement
	}
		

	// two condition yes or no format
	// this or that
	if(condition){
		// if block statement
	}
	else{
		// else block statement	
	}


	string: sequence of characters.

	format specifier: 
		%d -> integer
		%c -> character
		%f -> float
		%lf -> double
		%p -> pointer address
		%s -> complete string.

*/

void main() {

	int a = 10;
	int b = 20;
	int c = 10;
	if (c > b) {
		printf("value of c is greater than b: %d\n",c);
	}



	// {greater, less, equal}
	if (a > b) {
		printf("value of a is greater than b: %d\n", a);
	}
	else {
		printf("value of a is less than b or equal to b: %d\n", a);
	}

	// multiple if else-if statement
	if (a > b) {
		printf("value of a is greater than b: %d\n", a);
	}
	else if(a<b) {
		printf("value of a is less than b: %d\n", a);
	}
	else {
		printf("value of a is equal to b: %d\n", a);
	}


	// traffic light system

	int signal = '\0';
	printf("\n\nEnter signal: ");
	scanf_s("%c", &signal);


	if (signal == 'g') {
		printf("Signal is green you can go, safe ride....\n");
	}
	else if (signal == 'o') {
		printf("Signal is orange be careful, you need to stop.\n");
	}
	else if (signal == 'r') {
		printf("Signal is red, Please stand here....\n");
	}
	else {
		printf("Signal is broken, call traffic police....\n");
	}

	printf("\n-----------------------------------\n");

}