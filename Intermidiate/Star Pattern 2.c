#include<stdio.h>

/*
	In this section we will make a start pattern as showing below.
	-------------
	* * * * * 
	* * * * 
	* * * 
	* * 
	* 
	-------------
	
	Logic:
		requirment, first create the start pattern 1.
		
		changes: 
			outer loop: intialization will start from n to 0; decrement in 
			each iteration.
			
			inner loop: 
			
*/


void main(){
	
	int i=0; // a counter to count number of rows.
	int j=0; // a counter to count number of columns.
	// this outer loop will make new line and
	// also will start the inner loop in each iteration.
	for(i=10; i>=0; i--){
		
		// now we will run our inner loop
		for(j=0; j<=i; j++){
			printf("*");
		}
		
		// Now after completing the each row we will create a new row.
		printf("\n"); // \n will create a new row.
		
	}
}
