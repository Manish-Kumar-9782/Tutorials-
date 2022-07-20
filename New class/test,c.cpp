#include <stdio.h>
#include <math.h>



int main(){
	
	char command =' ';
	
	printf("Do you want to do this action (y/n):  ");
	scanf("%c", &command);
	
	if (command =='y' || command == 'Y'){
		
		printf("Access Granted!");
	}
	else{
		printf("Access Denied!");
	}
}
