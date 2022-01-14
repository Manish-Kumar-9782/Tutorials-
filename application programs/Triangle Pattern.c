// Make a star pattern
// In this programs we will make a triangle pattern which will make a triangle.
#include<stdio.h>

void main(){
	
	int i,j,space,star, stars=1;
	// i and j are used to tranck row and column at which we will place either a blank space or star.
	// space: will count that how many blank space " "  to be printed in a row.
	// after printing the blank space we need to print stars.
	// star: will count that how many star has printed in a row.
	// stars: will hold and decide that how many stars need to be printed in each row to make a triangle.
	
	for(i=1,space=10; i<=10; i++, space--, stars+=2){
		
		// Now first of all we will run a loop for each row, here this outer loop will run for each row.
		printf("%4c"," "); // this print statement will make a offset from triangle pattern.
		star=0; // in each row printed star will started from 0;
		
		for(j=1; j<=20; j++){
			// Now we will count each column in each row.
			// first we will print blank space up to space number.	
			
			if(j<space)
				// if our column number lie in space number then we will print a blank space.
				printf(" ");
			else
			/* if our column number is greater than the space number it means that we have printed all 
			 blank space and now we need to start star printing in each column of each row.*/
				if(star <stars){
					printf("*"); 
					/* we will print star util we dont reach upto the limit of stars in each row 
					the limit of stars in each row is definied by the stars varaibe.*/
					star++;
					/* we need to count that how many stars have been printed in each row 
					so we can know that where to stop of printing stars and go for next row.*/
				}
		}
		printf("\n"); // Going for next row after printing one row.
	}
	
}
