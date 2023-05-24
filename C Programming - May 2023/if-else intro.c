#include<stdio.h>
/*
	if else statement:
		condition test.

	syntax: condition --> true or false
		if(condition){
			
		}
		
*/

void main() {
	int a = 10;
	int x = 60;
	int z = 170;
	// conditional statement
	if (a > 20) {
		printf("a is greater 20\n");
	}


	// if x is not less than 40
	// then else statement will run
	// Notes: if we have only two condition which can be treated as yes or no.
	if (x < 40) {
		printf("x is less than 40\n");
	}
	else {
		printf("x is greater than 40 or equal to 40\n");
	}
	// Note: else will run definitely if all above conditions are failed.


	// Now we will work on the multiple conditional statement.
	if (z<100) {
		printf("z is less than 100\n");
	}
	else if (z>100) {
		printf("z is greater than 100\n");
	}
	else {
		printf("z is equal to 100\n");
	}

	// non conditional statement
	printf("\n-------------------------------------------\n");
	printf("End of program\n");
}
