#include<stdio.h>

// in this section we will see the if else statement;
// if else statement are also called control statement because they control the conditions and gives the result according to them


// Program:  Check wether user age is greater than 18 or not.

/* if else statement

	if (condition )
		{
		statements
		}
	else{
		statement
		}
*/
#define MIN_AGE 18  // defining a MIN_AGE variable.

void main(){
	
	int age;
	
	printf("Enter your age: ");
	scanf("%d", &age);
	
	if (age >= MIN_AGE){
		// here we are checking (comparing ) the value of b (input value) with a (which is already defined.)
		printf("You are eligible to watch A+ rated movies.");
	}
	else{
		// if above condition does not satisfy then this statement will excute.
		printf("you are under age so can't watch the A+ rated movies.");
	}
}
