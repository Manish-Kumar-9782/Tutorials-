#include<stdio.h>

/*
	for loop:
		controlled loop, state-full loop, definite loop

		for(initialization;condition;increment/decrement){
			// body block
		}
		// body will till condition is true
		// condition --> counter variable dependent


		while(condition){
			//body block
			// before run each iteration condition will be test.
		}

		// do while loop syntax:
		do{
			// body block for do - while loop
		}	
		while(condition);
*/

void main() {

	// loop initialize
	for (int i = 0; i < 10; i++) {
		printf("current value of i: %d\n", i);
	}

	// first loop initialization --> counter variable initialization --> test condition
	// ---> execute body block ---> increment/decrement --> test condition --> execute body block
	// loop will continue to run until test condition results false

	printf("\n\n=====================================================\n");
	
	int i = 0;

	// table 2 up to 10

	while (i<10) {
		// condition is set to 1 or true then while become infinite loop
		// we can only break infinite loop with the help of some kind of event
		// or internal extra conditions.
		i++;
		printf("%d\n", i * 2);
	}
	printf("now i is: %d", i);

	
	printf("\n\n============================================\n");
	//do - while loop
	i = 8; // reassigning the i value.
	do {
		printf("current i value: %d\n", i);
		i++;
	} while (i < 10);
	printf("\n============================================\n\n");

	printf("\n\n============================================\n");
	//do - while loop
	i = 8; // reassigning the i value.
	while(i<10) {
		printf("current i value: %d\n", i);
		i++;
	}
	printf("\n============================================\n\n");
}