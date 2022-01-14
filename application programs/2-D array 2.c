// Program: Write a program to compute and print a multiplication table for numbers 1 to 5 .

#include<stdio.h>
#define ROWS 	5
#define COLUMNS 5

void main(){
	
	// now we need to make a program which will hold the numbers.
	int row, column, product[ROWS][COLUMNS];
	int i,j;
	
	printf("     MULTIPLICATION TALBE\n\n    ");
	
	// making heading of the columns.
	for(j=1; j<=COLUMNS; j++)
		printf("%4d", j);
		// this loop will print the heading of column in which we will show the multiplication table.
		
	// Now we will make a separate line
	printf("\n_________________________________\n");
	
	// Now we will compute the product of rows and column numbers.
	for(i=0; i<ROWS; i++){
		
		row = i+1;
		printf("%2d |", row);
		
		// now we need to make another loop for each column
		
		for(j=1; j<=COLUMNS; j++)
			{
				column =j; // now first we will make a copy of the column number or counting number.
				
				product[i][j] = row*column;
				printf("%4d", product[i][j]);
				
			}
			printf("\n"); // making a new line after end of the each row items.
	}
		
}
