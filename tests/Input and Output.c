#include<stdio.h>

// In this section we will see input and output statement by using the printf and scanf funcitons.

void main(){
	
	int a;
	char name;
	printf("Enter Your Number: ");
	scanf("%d",&a);
	printf("You Have entered: %d", a);
	
	printf("\nEnter your name: ");
	scanf("%c", &name);
	printf("\nYour name is %c :", name);
}
