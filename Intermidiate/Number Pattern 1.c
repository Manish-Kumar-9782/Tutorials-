#include<stdio.h>

// Number pattern.

/*  Our Pattern to print.
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

void main(){
	
	int i = 0, j = 0;
	
	// for row 
	for(i=1; i<=5; i++){
		
		for(j=1; j<=i; j++){
			printf("%d ",j);
		}
		printf("\n");
	}
}
