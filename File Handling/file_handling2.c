#include<stdio.h>
#include<string.h>

void main(){
	
	FILE *fptr;
	
	int id;
	char name[30];
	float salary;
	
	fptr = fopen("empt.txt", "w+");
	
	// Checking if our file present or not.
	if(fptr == NULL){
		printf("file does not exist!\n")
		return;
	}
	
	printf("Enter id ")
}
