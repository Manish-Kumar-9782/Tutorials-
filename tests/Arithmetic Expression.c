#include<stdio.h>

// In this section we will see some arithmetic precedence order of Operator
// also we will see some algebric expression 

void main(){
	
	int x, eq;
	const int a=3,b=2,c=1; // here we are making some constant integer type variable.
	// a, b, and c are read only variables we cannot change their value or neither we cannot assign different values to them.
	
	printf("Enter your variable x value: ");
	scanf("%d", &x);
	eq = a*x*x + b*x +c;
	printf("\n Your result: %d", eq);	

	//printf("trying to change the value of a and b , %d and %d ,", a=10,b=20);
	// by uncommenting above line cause read only error.
} 
