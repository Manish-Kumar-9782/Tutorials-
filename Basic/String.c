#include<stdio.h>
#include<string.h>

/*
	strcmp()
	strcpy()
	strlen()
	
*/

void OneDArray();
void OneDArray2();
void UsingStrCpy();

// Manish

// ---Manish---

void main(){
	
	
//	OneDArray();
	
	OneDArray2();

//	UsingStrCpy();

	// computing the length of the string.
//	char string1[15] = "Manish Kumar";
//	char string2[10] = "Hello";
//	
//	printf("Len of string1: %d", strlen(string1));
//	printf("\nLen of string2: %d", strlen(string2));
	
}

void OneDArray(){
	
	char Name[15] = "Manish Kumar"; // 1D array.
	printf("%s", Name);
	printf("\nEnter you Name: ");
	scanf("%s",&Name);
	
	printf("\nName: %s", Name);
	
}

void OneDArray2(){

	char Name[10]; // 1D array.
	char ch;
	printf("Enter you Name: ");
	
	gets(Name);  // get string.
	
//	getch(ch);
//	
	printf("\nName: %s", Name);
//	printf("ch: %c", ch);
//	
}


// perfoming assignment operation by using strcpy() function.
void UsingStrCpy(){
	
	
	char Name[10]; // 1D array.
	
	strcpy(Name, "Hello");  // copyinb the "hello" into Name variable.
	
	printf("Name: %s", Name);
	
}



