// make a triangle shpae using 2 for loop.

// In this section we wil use row and column concept in which one for loop will handle rows and another for loop will handle column.

#include<stdio.h>

void main(){
	
	int i, j, k; 
	// i for rows and j for columns.
	
	// making a outer loop to handle to rows.
	
	for(i=1, k=19; i<=20; i++, k--){
		// i will make a new line or handle rows.
		
		for(j=1; j<=20; j++){
			// inner loop will print column.
			if(j<=k)
				printf(" ");
			else
				printf("*");
		}
		
		printf("\n");
		//sleep(2);  // rows will be printed witin 1 second delay.	
	}
	
}
