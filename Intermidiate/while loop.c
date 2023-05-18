#include<stdio.h>

/*
	In this section we will learn about the while-loop how it id different to for-loop
	when to use it over for-loop.
	
	unlike for-loop, whlie-loop does not contain the three statmenet inside the 
	round brackets, it only contains the termination condition.
	
	syntax:
		while(condition){
		// statements.
	}
	
	To break the loop we can use external counter variable or we can use break statment
	inside the if-else conditons.
*/

void main(){
	
	// now we will create an infinite loop
	// if we don't apply any kind of termination condition then it will become 
	// the infinite loop.
	int i =0;
	
	// testing the termination conditon in each iteration.
	while(1){
		printf("running.....%d\n", i++);
		
		// to stop the loop we can make condition using if-else statment.
		if(i>1000){
			break; // stopping the while using break keyword.
		}
	}
}
