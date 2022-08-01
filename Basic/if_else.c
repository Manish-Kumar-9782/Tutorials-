
// if-else statemet
// 1. single if-esle or only if.
// 2. sequencal if - else
// 3. neseted if - else // ladder

#include<stdio.h>

void yes_no(char);
void yes_no2(char);

void main(){
	
	char cmd;
	printf("Enter you cmd: ");
	scanf("%c", &cmd);
	
	//calling yes_no
//	yes_no(cmd);

	yes_no2(cmd);
	
}

void yes_no(char ch){
	
	if(ch=='y'){
		printf("This is if statement\n");
		printf("You have pressed y");
	}
	else{
		printf("This is else statement\n");
		printf("You have pressed %c", ch);
	}
}


void yes_no2(char ch){
	
	if(ch=='y'){
		
		printf("This is if statement\n");
		printf("You have pressed y");
	}
	else if(ch == 'n'){
		
		printf("This is else-if statement\n");
		printf("You have pressed n");
	}
	else{
		printf("This is else statement\n");
		printf("You have pressed %c", ch);
	}
}

