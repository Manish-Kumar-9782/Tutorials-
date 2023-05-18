#include<stdio.h>

/*
	In this section we will leran to create a start pattern 
	
	Simple star pattern.
	--------------------
	*
	* *
	* * * 
	* * * *
	* * * * *
	* * * * * *
	--------------------
	Logic:
		In this we will have two loops one is outer loop and another is inner loop 
		which will be placed inside the outer loop.
		
	loop to control row:
		This loop will hanlde that when we should create a new new line.
		and also this will run the inner loop.
		
	loop to print the  row:
		to print the single row we have inner loop which will be responsible to print
		the stars in a single row.
		
		In our simple star pattern, the number of star to print handled by the 
		termination condition inner loop.
*/

void main(){
	
	int i=0; // a counter to count number of rows.
	int j=0; // a counter to count number of columns.
	// this outer loop will make new line and
	// also will start the inner loop in each iteration.
	for(i=0; i<10; i++){
		
		// now we will run our inner loop
		for(j=0; j<=i; j++){
			printf("*");
		}
		
		// Now after completing the each row we will create a new row.
		printf("\n"); // \n will create a new row.
		
	}
}
