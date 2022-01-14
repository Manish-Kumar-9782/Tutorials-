// In this program we will make a dimond pattern in which we will make two triangle 
// first triangle will be the from upside and second will be downside.

// Concept: we need to print two different triangel by using the 2-level nesting loop.
// firt 2-level nesting loop will print the upper part of the dimond
// second 2-level nesting loop will print the down part of the dimond.


#include<stdio.h>
#include<time.h>


void main(){
	
	int i,j,space,star, stars=1;
	// i and j are used to tranck row and column at which we will place either a blank space or star.
	// space: will count that how many blank space " "  to be printed in a row.
	// after printing the blank space we need to print stars.
	// star: will count that how many star has printed in a row.
	// stars: will hold and decide that how many stars need to be printed in each row to make a triangle.
	
	// we will total print 20 line in which 10 will for upsie triangle and 10 will for down side triangle.
	
	// --------------------------------	PRINTING UPSIDE TRIANGLE------------------//
	for(i=0, space=10; i<=10; i++, space--)
	{
		// we can make an offset of blank space for each row.
		printf("%5c"," ");
		
		
		star = 0; // initially no star is printed in each row.
		// i less than 10 will be our upside triangle section first we will print this.
		// Now we need to run another loop for each column.
		
		// Here also we need to decide taht how much space we need to print
		for(j=0; j<20; j++){
			//sleep(1);
			if(j<space)
				printf(" ");
			else
				if(star<stars){
					printf("*");
					star++;
				}
				else break;				
			
		}
		
		// NOw we need to go for next row after done with one row.
		printf("\n");
		
		// Now we will decide that how many stars to be printed in each row in upside triangle section.
		// increasing 2 stars for each row.
		stars += 2;
		
		if(space == 1) break;  // Now we have reached to the end of the no space we will stop our printing.
			
	}
	
	//----------------------------------PRINTING THE DOWNSIDE TRIANGLE---------------------------//
	
	
	// in this section we need to increase the spcae from 1 to 10 reverse of upside trinagle.
	for(i=0, space=1; i<=10; i++, space++){
		
		// we can make an offset of blank space for each row.
		printf("%5c"," ");
		
		
		// here also we need to decrease the stars by 2, to be printed in each row.
		stars -= 2;
		
		// counting printed stars starts from zero.
		star = 0;
		
		// Now we will print the stars in each column
		
		for(j=0; j<=20; j++)
		{
			
			if(j<space)
				printf(" ");
			else
				if(star< stars){
					printf("*");
					star++;
				}
		}
		// Now after printing each row we need to go for next row by making a new line
		printf("\n");
	}
	
}
