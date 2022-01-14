//  making a factorial funciton.
#include<stdio.h>
#include<time.h>

// 1. No return type and no argument.
// 2. NO return type with argument.
// 3. Return type no argument.
// 4. Return type with argument.

int factorial(int n);

void main(){

	int n;
	int result=0;
	printf("Enter the Value: ");
	scanf("%d", &n);
	
	result = factorial(n);
	
	printf("\nFactorial of %d:  %d", n,result);
	
}

int factorial(n){
	
	int i=0;
	int result=1;
	
	for(i=n; i>=1; i--){
		//sleep(1);
		printf("%d",i);
		result = result*i;
		if(i!= 1)
			printf("x");
	}
	
	return result;
}

