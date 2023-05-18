#include<stdio.h>

/*
	do-while: it similar to the while loop except do block comes first and after the
	do block we put the while statment.
	
	in this at very first iteration, do block will run first after that while condition
	will be tested.
*/

void main(){
	
	int i=-3;
	
	do{
		printf("i is %d\n", i);
	}
	while(i>0);
	
	// in above case if `i` is less than 0 then it will not run after the 
	// first execution of the do{} block.
}
