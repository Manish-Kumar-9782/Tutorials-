#include<stdio.h>

// In this section we will see how to control the flow of code by
// using some conditional statement.

/*
	if-else conditional statement:
	
		if else statement are used to control the flow on code block execution
		if test for each condition in defined sequence.
		
	// 1. single if statement.
	
	
	if(condition){
		// code block with one or more than on line of code.
		// other... statements.
	}
	
	Note: if 'condition' satisfied, which is defined inside the round brackets along with 
	'if' keyword. then the defined code block after the round bracket will be 
	executed.
	
	if condition not satisfied then block will not be executed.
	
	
	// 2. if-else statement: this or that type of situation.
	
	if(condition){
		// code block	
	}
	else{
		// code block
	}
	
	Note: in this we only test the condition with if statement. if, 'if' condition
	satisfied then only if block will run , if, 'if' condition is not satified then 
	else block will be selected with out checking any condition.
	
	// 3. if, else if, else statement.
	this type of  statement is used for multiple condition.
	
	if(condition-1){
		// code block	
	}
	else if(condition-2){
		// code block
	}
	else{
		// code block
	}
	
	Note: Now in this type of situition, each condition is tested in given 
	order. if any condition is staified, then it's related block will be 
	executed and other condition will be skipped.
	
	Note: if any condition is not satisfied then last else block will be executed.
*/

void main(){
	
	// 1. single condition if statement.
	
	int a = 10;
	int b = 20;
	
	printf("a = %d, b = %d \n", a, b);
	// Now we want to test that, a is greater than b.
	
	if(a>b){
		printf("a is greater than b.\n");
	}
	printf("......\n");
	
	// Now we want to test that, b is greater than a.
	if(b>a){
		printf("b is greater than a. \n");
	}
	
	//--------------------------------------//
	
	// 2. if-else statment:
	printf("\n\n===============================\n");
	printf("if-else statemet\n");
	
	if(a>b){
		printf("a is greater than b.\n");
	}
	else{
		printf("b is greater than a. \n");
	}
	
	// 3. if, else if, else statement
	
	printf("\n\n===============================\n");
	printf("if, else-if , else statemet\n");
	
	a = 20;
	
	if(a>b){
		printf("a is greater than b.\n");
	}
	else if(a<b) {
		printf("b is greater than a. \n");
	}
	else{
		printf(" a is equal to b. \n");
	}
}
