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

	/*	counter controlled loop
		for(initialization; condition; increment/decrement ){
			// for loop body
		}
	*/


	// dev c++  
	//int i;  inside dev c++

	/*for (int i = 0; i < 12; i++) {
		printf("%d\n", i);
	}*/


	// while loop
	// sentinel loop

	char ch = '\0';
	// \0 --> null character

	// infinite loop
	// run each cycle, until we don't have '\n' character inside ch variable.
	printf("Enter your string: ");
	while (ch != '\n') {
		scanf_s("%c", &ch);
		printf("%c\n", ch);
	}
	printf("--------------------");
	
	scanf_s("%c", &ch);
}