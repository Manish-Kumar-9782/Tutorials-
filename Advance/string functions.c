#include<stdio.h>
#include<string.h>
/*
	string handling functions:
		
		strcat(): concatenation.
		strcmp(): string comparison
		strcpy(): to copy one string to anoter array of char.
		strlen(): to get the length of string.
		
*/

void main(){
	
	// first we will make two strings.
	char firstName[20] = "manish";
	char lastName[] = "kumar";
	
	// Now we will concate our name1 and name2.
	
	
	// the result value will be stored in the new fullName char Array.
	printf("first Name: %s\n", firstName);
	printf("last Name: %s\n", lastName);
	
	strcat(firstName, " ");
	strcat(firstName, lastName);
	printf("fullName: %s\n", firstName);
	
	
	//------------- Comparing two strings ----------- //
	
	char color1[] ="red";
	char color2[] ="green";  
	int result = strcmp(color2, color1);
	
	/*
		strcmp will give us the result if 
		first value:
			equal  = 0;
			less than = -1;
			greater than = 1;
	*/

	printf("is color1 is equal to color2: %d\n", result);
	
	//-------------------- copying an string to another array ---------//
	char newColor[10] ={'\0'};
	// copying color2 value into newColor
	strcpy(newColor, color2);
	printf("new Color: %s\n", newColor);
	
	// we can't do newColor = color2; this will give us error.
	
	//------------- computing the length of string---------------- //
	// Now first name container "manish kumar" we will compute 
	// how many characters are present inside the firstName.
	
	int len = strlen(firstName);
	
	printf("length of firstName: %d", len);
	
}
