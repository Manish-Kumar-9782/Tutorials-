// while indefinite loop but not infinite loop

#include<stdio.h>

// Entry controlled loop or pre test loop.

void main(){
	
	
	int i=50;  // here is a control (sentinel) variable
	
	while(i<=100)  // first of all we will test the condition
	{	
		// while loop will be executed until the above test condition is not satisfied.
		printf("count %d\n", i++); // after testing the condtion we will execute the block.
	}
	
	printf("End of the loop.");
}
