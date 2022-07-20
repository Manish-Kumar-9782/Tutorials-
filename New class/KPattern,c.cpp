
/*

**********
*********
********
*******
******
*****
****
***
**
*
*
**
***
****
*****
******
*******
********
*********
**********


*/

#include<stdio.h>

int main(){
	
	int i; // to hold the index number of row.
	int j; // to hold the index number of column.
	
	// Outer loop : this will control the rows
	// in each iteration it will change the row and also run the inner loop
	for(i=1; i<=10; i++){
		
		// Inner loop: this will control the column in each row.
		// in each iteration it will print * in columns upto i number
		// this loop will run in each iteration of Outer loop
		for(j=10; j>=i; j--){

			printf("*"); // to print * on columns conrolled by inner loop
		}
		
		printf("\n"); // to change the row, controlled by outer loop
	}
	
	/*--------------------------------------------------------------------*/
	
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
