#include<stdio.h>

/*
* (): parenthesis
* {}: curly braces
* []: square brackets
* 
* 
	while(condition){
		// statement
	}
*/

// void is here return type.
void main() {

	int i = 0; // external variable 
	char name[10]; // array
	int age=0;
	float height = 0.0;
	
	printf("Enter Student Name: ");
	scanf("%s", &name);
	
	printf("Enter Student Age: ");
	scanf("%d",&age);
	
	printf("Enter Student Height: ");
	scanf("%f",&height);
	
	printf("\n=================================\n");
	printf("Name: %s\n",name);
	printf("Age: %d\n",age);
	printf("Height: %f\n",height);
}
