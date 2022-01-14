// make a program to check that today is sunday.
#include<stdio.h>

#define SUNDAY 0 // defining sunday at 0 position in the week days..

// Now we need to input the value of today and we will match that day value with our sunday.

void main(){
	
	
	int today;  // in this varialbe we will store the input today value.
	
	printf("Enter the today number: ");
	scanf("%d", &today);
	
	// now after getting the today number we need to match the value.
	
	if (today == SUNDAY){
		printf("\nToday is Sunday");
	}
	else{
		printf("\nToday is not Sunday");
	}
}
