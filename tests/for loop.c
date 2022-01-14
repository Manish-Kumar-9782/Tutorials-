#include<stdio.h>

// for loop: Counter controlled loop 

// Control Variable is incremented or updated to test the conditon.


void main(){
	
	int i;  // declaration of the variable  for(initialization; condition; increment/decrement or updatation)
			// here we will take i as the control variable.
	
	for(i=1; i<=100; i++)
	{
		
		// 1. first of all it will test the condition
		// 2. after testing the condition it will execute the code block or body of the loop.
		// 3. after execution of the body of the loop it will update the control varialbe.
		printf("Count %d\n", i);
	}
	
	printf("\nend of the for loop");
} 

