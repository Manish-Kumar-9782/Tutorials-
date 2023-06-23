#include<stdio.h>

/*
	while loop: each iteration will be tested before run.
		test performs at top.
		
	do-while: each iteration will be tested after running the very first 
	iteration.
		test perform at bottom.
*/

void main() {

	int a = 9;

	while (a < 10) {
		printf("while loop ");
		printf("count: %d\n", a);
		a++;
	}

	a = 9;
	do {
		printf("do-while ");
		printf("count: %d\n", a);
		a++;
	} while (a < 10);


}