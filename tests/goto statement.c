#include<stdio.h>
#include<math.h>
// program: compute the square root of five  numbers by using the goto statement.

void main(){
	
	int x;
	float y;
	int count;
	count = 1;
	
	printf("Enter the five real values in a line:");
	
	read:
		printf("\n");
		scanf("%d", &x);
		printf("\n"); // creating a new line after input values
		
		if (x<0)
			printf("Value - %d is negative \n", count);
		else
		{
			y = sqrt(x);
			printf("%d\t:\t%.2f", x,y);			
		}
		
		// now we need to count the number of inputted numbers.
		count +=1;
		
		// now we need to set the condition for the backward jump.
		
		if (count <= 5)
			goto read;
		
		// if our count is less than 5 then our program will jump to the read: label.
		// if our count is greater than 5 then wew ill skip the goto statement and print the end of the program.
		printf("\n---------END OF PROGRAM--------------\n");
		
		
	
}
