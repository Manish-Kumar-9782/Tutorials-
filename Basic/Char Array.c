#include<stdio.h>

/*
	In this section we will see how to create a string, by using the array of characters.
*/
void printArray(char[], int);
void main(){
	
	char name[10] = {'m','a','y','a','n','k','\0','\0'};
	// \0: it is a null character, it tells the compiler that our string 
	//has been finished.
//	printf("Name: ");
//	printArray(name, 10);
	printf("Name: %s\n", name);
	
	char name2[] = "Manish Kumar";
	
	printf("Name: %s\n", name2);
	
	// Now we will take input from user.
	char Name[10] ={0};
	
	printf("Enter you Name: ");
	gets(Name);// gets() function is used to get the string input from user.
	printf("Entered Name: %s\n", Name);
	
	char longName[10] = {'m','a','y','a','n','k',' ','d', 'h','a','k','e','d','\0'};
	printf("overflow Name: %s\n",longName);
	
}


