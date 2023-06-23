#include<stdio.h>

/*
* (): parenthesis
* {}: curly braces
* []: square brackets
* 
* 
	while(condition){
		// statement
	}
*/

// void is here return type.
void main() {	
	// inner loop 
	// outer loop
	int i = 0, j = 0;
	// i --> row contained by outer loop
	// j -> column contained by inner loop
	for (i = 1; i <= 10; i++) {

		for (j = 1; j <= 10; j++) {
			printf("* ");
		} // filling the single line each time.

		printf("\n"); // creating a newline
	}
}