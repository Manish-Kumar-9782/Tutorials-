#include<stdio.h>

// In this Section we will discuss on the switch statement.

/*
	switch statement
	
	syntax:
		switch(contant value){
			
			case constantValue: 
				// first case code space.
				break;
			case constantValue:
				// second case code space.
				break;
			...
			
			default:
				// default statement.
				break;
		}
		
		Note: switch statement does not accept any kind of 
		expressions. it only works on the constant values.
		
		constant values: values who meaning bit's values does 
		not change over time.
		
		Note: in c, switch statement does not work with strings.
		only characters and number.

*/

void main(){

	// Now first of all we will make a variable, for not int type.
	
	int value = 1; // declaring and initializing the value
	// if we initialize the variable it reduce the 
	// run time computation with garbage value.
	
	switch(value){
		
		case 1: 
			printf("\nThis is case 1.");
			break;
		
		case 2:
			printf("\nThis is case 2.");
			break;
			
		default:
			printf("\nThis is default Case.");
			break;
			
		// In each case we must put the break statement if
		// we dont want to execute the below or next case.
		
		// break keyword: in our switch case statement break keyword
		// tells us the our case is terminated/closed here.
	}
	
	
}
