// Program: In this section we will make a Inverted Pyramid of stars..

/*
		* * * * * * * * *
		  * * * * * * *
		    * * * * *
		      * * *
		        *
*/

// Our result should be look like this. 
#include<stdio.h>

void main(){
	
	// to make a half pyramid program we need two loop 
	// one loop will track the row and other one will track the columns.
	int i,j, space, k=0,stars=20;
	
	for(i=1,space=1; i<=10; i++, space++){
	
		// Now to make a fully inverted pyramid of stars we need to
		
		for(j=1; j<=stars; j++)
		{
			
			// first we will print the blank space and then we will print the numer.
			if(j<=space)
				printf(" ");
			else
				if(k<stars)
				{
					printf("*");
					k++;
				}
				
				
		}
		printf("\n");
		
		// Now we need to increase the number of stars need to be printed in next row.
		stars -=1;
		k=0;
	}
}
