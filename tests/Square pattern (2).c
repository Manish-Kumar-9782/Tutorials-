// Program: make a square pattern.

#include<stdio.h>
#include<time.h>  // time.h is a library which contain functions related to the time.

void main(){
	
	int i;
	
	for(i=1; i<=50; i++){
		
		sleep(1);  // it makes delay in the execution of the pritf() statement.
		printf("*");
		
		if (i%10==0){
			printf("\n");  // if we have got 10 stars then we will make a new line.
		}
	}
}
