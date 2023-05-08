#include<stdio.h>

/*
*	a += 1; ---> a++; a--; ++a, --a;
	For loop Syntax:
	for(statement1;statement2;statement3){
		// body block statements
	}

	// statement1: initialization of counter variable
	// statement2: test condition in result true of false
		if true loop will continue, if false loop will be stopped.
	// statement3: increment or decrement of counter variable.
	var++;

	for(initialization;condition;increment/decrement){
		// body block statements
	}

	// while loop

	while(condition){
		// body block for while loop
	}

*/

void main() {

	int i;
	char ch;

	for (i = 0; i < 10; i++) {
		printf("count ");
	}
	printf("\n\n");
	// infinite loop

	printf("Enter integer any number: ");
	scanf("%d", &i);  // & ampersand  memory address operator

	printf("You Have entered this number: %d", i);
	
	while(1){
		
		scanf("%c",&ch);
		if(ch=='q'){
			break;
		}
		
	}
	
	
}
