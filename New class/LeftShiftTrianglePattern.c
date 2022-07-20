/*--------------------------Documentation Section---------------------------*/

/* In this section we will make a pattern as showing below. */


/*

*
**
***
****
*****
******
*******
********
*********
*/

/*
	Logic to create this pattern;
	1. first of all make two int variable i and j.
	2. now make a loop (outer loop ) which will act as controlling the position of the row.
	3. make i as the counter varaible of the outer loop.
	4. make another loop inside the outer loop, this loop will act as controlling column in each rows.
	5. make j as the counter variable of the inner loop.
	6. print one stare in inner loop
	7. print a new line after closing the inner loop
*/

/*
	PseudoCode:
	
		counter i;
		counter j;
		
		for each row in i do:
			for each column in j do:
				print *
			
			print newline;
	*/
	
/* For Current Pattern:
	
	counter i;
	counter j;
	
	Outer loop will run i<=10, (initialised from 1), i++ in each iteration.
		
		Inner loop will run	upto j<=i; (initialised from 10), j++ in each iteration. 
			print * in inner loop.
			
		print \n in Outer loop.
			
*/

#include<stdio.h>
#include<time.h>

int main(){
	
	int i; // i to hold the index number of row.
	int j; // j to hold the index number of column.
	
	// Outer loop : this will control the rows
	// in each iteration it will change the row and also run the inner loop
	for(i=1; i<=10; i++){
		
		// Inner loop: this will control the column in each row.
		// in each iteration it will print * in columns upto i number
		// this loop will run in each iteration of Outer loop
		for(j=1; j<=i; j++){
		
			printf("*"); // to print * on columns conrolled by inner loop
		}
		printf("\n");  // to change the row, controlled by outer loop
	}
	
}
