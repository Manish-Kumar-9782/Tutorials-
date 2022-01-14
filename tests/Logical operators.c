#include<stdio.h>

// in this section we will see the logical operator;
// Logical operators are used in decision making and loops.
// with control statements;
void main(){
	

 	int a, b, c;

	// assigning a and b
 	a = 10;
 	b = 5;
 	c=15;

	printf("\n&& operator: \n");

	if (a == 10 && b==6){
		
		// Here we have applied the condition on a and b 
		// if a and b are both equl to their respective values then below line will be printed.
		
		printf("we have a = 10 and b = 5");
	}
	else{
		// if any one them (from a and b conditions) is not satisfied then below line will be printed.
		printf("One of them is not matched our conditions");
	}

	printf("\n\n || Operator: \n");
	
	if (a == 11 || b==6 || c==7){
		
		// Here we have applied the condition on a and b 
		// if a and b are both equl to their respective values then below line will be printed.
		
		printf("One of them or both conditions are satisfied.");
	}
	else{
		// if any one them (from a and b conditions) is not satisfied then below line will be printed.
		printf("Both condition not satisfied.");
	}
	
}
