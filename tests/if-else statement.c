#include<stdio.h>

// in this section we will see the if else statement;
// if else statement are also called control statement because they control the conditions and gives the result according to them


// Program:  check wether a input value is greater then a defined value.

/* if else statement

	if (condition )
		{
		statements
		}
	else{
		statement
		}
*/
void main(){
	
	int a=100, b;
	
	printf("Enter your number: ");
	scanf("%d", &b);
	
	if (b > a){
		// here we are checking (comparing ) the value of b (input value) with a (which is already defined.)
		printf("Input value is greater than 100 < %d", b);
	}
	else{
		// if above condition does not satisfy then this statement will excute.
		printf("Input value is less than 100 > %d",b);
	}
}
