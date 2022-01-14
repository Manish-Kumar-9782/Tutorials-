// Program: In this section we will make a Full pyramid of Numbers.

/* 		1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5*/

// Our result should be look like this. 
#include<stdio.h>

void main(){
	
	// to make a half pyramid program we need two loop 
	// one loop will track the row and other one will track the columns.
	int i,j, space, k=1,n=1;
	for(i=1,space=20; i<=9; i++, space -=2){
		
	// Note 1: in this space value must be reduced by 2 if we want the same result as showing above
	// Note 2: we also need to make enough space so we can show the full result.
	// Note 3: after one specific value of j we need to reduce the integer value by one in each column.
		
		for(j=1,n=i; j<=k+space; j++){
			
			// first we will print the blank space and then we will print the numer.
			if(j<=space)
				printf(" ");
			else
			
				// Now here after the all first blank space 
				if(j<=k/2+space)
					printf("%d ",n--);
					// we will reduce the value of integer until j-th value does not reach to mid point of pyramid.
				else
					printf("%d ",n++);
					// we will increase the value of integer after reaching the mid point of the pyramid.
		}
		printf("\n");
		
		// Now we need to increase the number of stars need to be printed in next row.
		k += 2;
		
	}
}
