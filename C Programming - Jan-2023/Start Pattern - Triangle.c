#include<stdio.h>

/*
	*
	* *
	* * *
	* * * *
	* * * * *

	outer for loop:
		counter variable:  i
		it creates a new line
	
	inner for loop: 
		counter variable:  j
		it fills a single line at a time.

	* * * * *
	* * * * 
	* * * 
	* * 
	* 
*/

void main() {

	// two counter variables.
	int i = 0, j = 0;

	// outer loop
	for (i = 0; i < 10;i++) {

		// filling the current cycle line
		for (j = 0; j <= i; j++) {
			printf("* ");
		}

		// creating a new line in each cycle.
		printf("\n");
	}

	// reverse triangle
	int lines = 10;
	for (i = 0; i < lines+1;i++) {

		// filling the current cycle line
		for (j = 0; j <= lines-i; j++) {
			printf("* ");
		}

		// creating a new line in each cycle.
		printf("\n");
	}

}