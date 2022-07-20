/*
	== : it is relational operator, to detect the equality of the variable. (for example to match the vlaue of a and b variable.)
	
	Note: char is always defined in single quotes 'a' like a is defined.
*/



#include <stdio.h>


int main(){
	
	char command ='\0';
	
	printf("Do you want to delete file (y/n): ");
	
	scanf("%c", &command);
	
	if (command == 'y'){
		
		printf("file Deleted!");
		
	}
	else{
		printf("File not deleted!");
	}
}
