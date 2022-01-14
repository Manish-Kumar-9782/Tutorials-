// in this section we will make a program which will display a matrix and manipulate its value
// 

#include<stdio.h>
#include<time.h>
void main(){


// 2-dimensional arry working as matrix.

	int matrix[3][3] = {1,2,3,4,5,6,7,8,9}; // this is a list of array. { {1,2,3}, {4,5,6}, {7,8,9} };
	int matrixT[3][3] = {{0}, {0}, {0}};
	
	// matrix: it is used to hold the original matirx
	// matrixT: it will be used to hold the Transposed of original matirx.
	
	int i,j;
	
	printf("Our original matrix: \n\n");
	
	for(i=0; i<3; i++){
		// we are running this loop to track each row
		
		for(j=0; j<3; j++){
			
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
		
	}
	
	printf("Transposed matrix: \n\n");
	
	
	for(i=0; i<3; i++){
		// we are running this loop to track each row
		
		for(j=0; j<3; j++){
			
			matrixT[j][i] = matrix[i][j];
		}
	}
	
	
	for(i=0; i<3; i++){
		// we are running this loop to track each row
		
		for(j=0; j<3; j++){
			
			printf("%d ", matrixT[i][j]);
		}
		printf("\n");
	}
	
	
	printf("Making matrixT zero-digonal matrix: ");
	
	for(i=0; i<3; i++){
		// we are running this loop to track each row
		
		for(j=0; j<3; j++){
			
			if(i==j){
				matrixT[i][j] = 0;
				break;
			}
		}
		printf("\n");
	}
	
	
	for(i=0; i<3; i++){
		// we are running this loop to track each row
		
		for(j=0; j<3; j++){
			
			printf("%d ", matrixT[i][j]);
		}
		printf("\n");
	}
	
	
	

}
