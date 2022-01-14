#include<stdio.h>

#define PASSWORD 725257

void main(){
	
	int input_password;
	
	printf("Enter the password:");
	scanf("%d", &input_password);
	
	if(input_password == PASSWORD){
		
		printf("Access Granted");
	}
	else{
		printf("Access Denied");
	}
}
