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
*********
********
*******
******
*****
****
***
**
*

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
	
	8. Repeat 2 to 7 steps to make another pattern in different order
*/

/*
	PseudoCode:
	
		counter i;
		counter j;
		
		<< For above part of the pattern >>
		for each row in i do:
			for each column in j do:
				print *
			
			print newline;
			
		<< for below part of the pattern >>	
		for each row in i do:
			for each column in j do:
				print *
			
			print newline
		
	*/
	
/* For Current Pattern:
	
	counter i;
	counter j;
	
	<< for upper part of the pattern >>
	Outer loop will run i<=10, (initialised from 1), i++ in each iteration.
		
		Inner loop will run	upto j<=i; (initialised from 10), j++ in each iteration. 
			print * in inner loop.
			
		print \n in Outer loop.
		
	<< for below part of the pattern>>
	Outer loop will run i<=10, (initialised from 1), i++ in each iteration.
		
		Inner loop will run	upto j>=i; (initialised from 10), j-- in each iteration. 
			print * in inner loop.
			
		print \n in Outer loop.
			
*/

/*=========================================================================*/


#include<stdio.h>
#include<time.h>


// Note: to practice/run this program please see Left Shift Triangle Pattern and Right Shift Triangle Pattern

int main(){
	
	int i; // i to hold the index number of row.
	int j; // j to hold the index number of column.
	
	// this nested loop will print the Left Shift Triangle Pattern
	for(i=1; i<=10; i++){
//		sleep(1);  // to pause the program for 1 second after changing the row.
		for(j=1; j<=i; j++){
//			sleep(1); // to pause the program for 1 second after changing the column.
			printf("*");
		}
		printf("\n");
	}
	
	// This nested loop will print the Right Shift Triangle Pattern.
	for(i=1; i<=10; i++){
		
		for(j=10; j>=i; j--){
			printf("*");
		}
		printf("\n");
	}
	
}
