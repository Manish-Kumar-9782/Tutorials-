// Program: make a progrma which can make a transpose of a matrix. for simplicity take a 3x3 matrix.

#include<stdio.h>
#include<conio.h>

void main(){
	
	// first make all required variables.
	
	int i,j, matrix1[3][3], matrix2[3][3];
	/*
		Here i and j will represent the row and column of the matrix.
		matrix1 array will be our inputted original matrix.
		matrix2 array will be transposed array.
	*/
	
	printf("Enter a 3x3 matrix: \n");
		/*---------------------------------------------------------------------------------------------*/
	for(i=0; i<3; i++){
		
		// Now we need to input each row element one by one.
	
		for(j=0; j<3; j++){
			printf("a[%d][%d] = ", i,j);
			scanf("%d", &matrix1[i][j]); // inputting the matrix value
		}
	}
	
	// Now we need to show the enterd matrix values in the form of matrix.
	// for that we need to make another nesting loop to print each element in the form of matrix.
		/*---------------------------------------------------------------------------------------------*/
	printf("\n Entered Matrix \n");
	for(i=0; i< 3; i++){
		
		for(j=0; j<3; j++){
			printf("%2d", matrix1[i][j]);
		}
		printf("\n");
	}
	
	// Now we need to make the transpose the matrix1 into matrix2.
	// The simple concept of making a transpose is that we need to swap of each row element at column position
	/*---------------------------------------------------------------------------------------------*/	
	for(i=0; i< 3; i++){
		
		for(j=0; j<3; j++){
			matrix2[i][j] = matrix1[j][i];
		}
	}
	
	/*---------------------------------------------------------------------------------------------*/
	// Now after making the transpose of the matrix we need to display the transposed matrix.
	
	printf("\n Transposed Matrix \n");
	
	for(i=0; i< 3; i++){
		
		for(j=0; j<3; j++){
			printf("%2d", matrix2[i][j]);
		}
		printf("\n");
	}
	
}
