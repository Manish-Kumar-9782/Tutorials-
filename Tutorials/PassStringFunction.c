// In this section we will see how to pass a string in a function.

#include<stdio.h>

void display(char xyz[]);// declaration of the display function.
void display2(char xyz[]);

int main(){
	
	char name[12];
	printf("Enter Your name: ");
	gets(name);
	
	display(name);
	display2(name);
	
	
}

// definition of the display function.

void display(char name[]){
	
	printf("display 1 function: Hello my name is %s, and who are you?", name);
}


void display2(char name[]){
	
	int i=0;
	printf("\n\ndisplay 2 function: Hello my name is ");
	
	do{
		printf("%c",name[i]);
		i++;
	}
	while(name[i] != '\0');
	
	printf(" and who are you?");
}

