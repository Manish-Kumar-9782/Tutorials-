#include<stdio.h>

// do while loop 

// difference b/w while and do while loop

// exit controlled loop or post test loop.

void main(){
	
	int i=0;
	
	do{
		printf("count %d\n", i++);	 // first of all we will execute the code block 
	}
	while(i<=100); // after the code block execution we will test the condition. post test loops
	
	do printf("count %d\n", i++); while(i<=1000);
}
