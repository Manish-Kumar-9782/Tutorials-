#include<stdio.h>
#include<string.h>

// if -else statement

/*
*	// if - else condition for yes or no // this or that
	if(condition){
	}
	else{
	}
*/


void main() {

	int age;

	//printf("Enter age: ");
	//scanf_s("%d", &age);

	//// if only works for true.
	//if (age >= 18) {
	//	printf("You are an adult...\n");
	//}
	//else {
	//	printf("You are not an adult...\n");
	//}

	//int x; 
	//printf("Enter value of x: ");
	//scanf_s("%d", &x);
	//// {less than, greater than, equal}
	//if (x < 34) {
	//	printf("x is less than 34");
	//}
	//else if (x > 34) {
	//	printf("x is greater than 34");
	//}
	//else {
	//	printf("x is equal to the 34");
	//}


	// switch statement
	int value = 0;

	printf("Enter a number: ");
	scanf_s("%d", &value);

	switch (value) {

	case 1:
		printf("Case 1 output");
		break;

	case 2:
		printf("Case 2 output");
		break;

	case 3:
		printf("Case 3 output");
		break;

	case 4:
		printf("Case 4 output");
		break;

	default:
		printf("This is default output");
	
	}
}