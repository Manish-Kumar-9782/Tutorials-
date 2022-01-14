// Program: In this section we will make a Full pyramid of stars.
// In this program we will print a full pyramid of stars by printing i+2 stars in each line except first row.
#include<stdio.h>

void main(){
	
	// to make a half pyramid program we need two loop 
	// one loop will track the row and other one will track the columns.
	int i,j, space, stars=1;
	for(i=0,space=10; i<=10; i++, space--){
		
		// Here we will make some offset so we can see the pyramid of 10 rows easily.
		printf("%7c"," "); // this will print some extra blank space in each line
		// so we can see full pyramid.
		
		for(j=1; j<=stars+space; j++){
			
			// first we will print the blank space and then we will print the stars.
			if(j<=space)
				printf(" ");
			else
				printf("*");			
		}
		printf("\n");
		
		// Now we need to increase the number of stars need to be printed in next row.
		stars += 2;
		
	}
}
