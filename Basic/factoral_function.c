#include<stdio.h>

void factorial(int); // declaration.

long long unsigned int factorial2(int); // this function will return long long unsigned int type data.

void main(){
	int value=20;
	int i =0;
	
	long long unsigned int fact = 0;
	
	
	for(i=1; i<=value; i++){
		
		fact = factorial2(i);
		printf("\nfact %d: %llu\n",i, fact);
	}
	
	
}

void factorial(int number){
	
//	printf("\nInside the factorial function -- number: %d\n", number);
	
	long long unsigned int fact =1;
	
	int i=0;
	for(i=1; i<=number; i++){
		fact *= i; // fact = fact * i;
	}
	
	printf("\nfactorial of %d : %llu \n", number, fact);
	
}

long long unsigned int factorial2(int number){
	
	long long unsigned int fact =1;
	
	int i=0;
	for(i=1; i<=number; i++){
		fact *= i; // fact = fact * i;
	}
	
	return fact;
}





