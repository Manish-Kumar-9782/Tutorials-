
// Program: Calculate the factorial of x.

#include<stdio.h>

void main(){
	
	int x, factorial=1;
	
	printf("Enter the Value of X: ");
	scanf("%d", &x);
	
	if(x==0)
		printf("Factorial of X: %d", factorial);
	
	else{
		
		for(; x>1; x--){
			factorial *= x;
		
		}
		printf("Factorial of X: %d", factorial);
	}
	

}
