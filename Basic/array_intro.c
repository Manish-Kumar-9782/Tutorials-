#include<stdio.h>

void getName();
void getPass();

void main(){
	
	// array: 
	getPass();
	
}

void getName(){
	
	int nameSize = 10;
	
	char name[nameSize]; // array name 
	printf("Enter your Name: ");
	int i;
	
	for(i=0; i<nameSize; i++){
		scanf("%c", &name[i]);
	}
	
	printf("\n------------------------------------------------------\n");
	
	for(i=0; i<nameSize; i++){
		printf("%c", name[i]);
	}
	
}

void getPass(){
	
	int nameSize = 10;
	int flag = 1; // be default it true.
	
	char pass1[nameSize]; // input password
	char pass2[10] = {'a','b','c', 'd', 'e', 'f','g','h','i','j'}; // saved password
	
	printf("Enter your Password: ");
	int i;
	
	for(i=0; i<nameSize; i++){
		scanf("%c", &pass1[i]);
	}
	
	// compare each value
	
	for(i=0; i<nameSize; i++){
		
		if(pass1[i] != pass2[i]){
			flag = 0;
			break;
		}
	}
	
	// 
	if(flag == 1){
		printf("Access Granted");
	}
	else{
		printf("Accesss Denied");
	}
	
}


