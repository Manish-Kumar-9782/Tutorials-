//  in this section we will see the definition of function  and declaration of functions.
#include<stdio.h>
#include<time.h>

void print_matrix(int arr[3][3]);  // 1. function declaration.


void main(){

// 1. declaration
// 2. definition
// 3. call.

// return-type  function-name  parameter list; 
	int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
	int matrixT[3][3] = {{0},{0},{0}};
	int uni_matrix[3][3] = {{1,1,1,},{1,1,1},{1,1,1}};
	int zero_matrix[3][3] = {{0},{0},{0}};
	int i, j;
	print_matrix(matrix); // not return type. but having one argument.
	
//	printf("Transposed matrix: \n\n");
	
	
	for(i=0; i<3; i++){
		// we are running this loop to track each row
		
		for(j=0; j<3; j++){
			
			matrixT[j][i] = matrix[i][j];
		}
	}
	
	printf("\nTransposed Matrix\n");
	print_matrix(matrixT);
	
	printf("\nUnit matirx\n");
	print_matrix(uni_matrix);
	
	printf("\nZero Matrix\n");
	print_matrix(zero_matrix);
	
	
}

void print_matrix(int arr[3][3]){
	// 2. function definition.
	int i,j;
	for(i=0; i<3; i++){
		
		for(j=0; j<3; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
}
