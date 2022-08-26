#include<stdio.h>
#include<string.h>

/*
	In this section we will read a file by uisng the fgetc function.
	
	int fgetc(FILE *stream)
	
	It only take file pointer (single argument) as argument.
	
	fgetc function will only read a single character at a time.
	
	Note: it will reaturn EOF at the end of the file.  
*/

void main(){
	
// FILE *fopen( const char * filename, const char * mode );  

/* 	fopen funciton takes two argument type of const char* 
	first argument takes the file name  
	second argument takes the file mode
	
	file name: file can be stored at any location so we can use relative 
			  or absolute file address.
			  
	Note: Since our file is stored (or to be stored) in the current 
		directory we only have to pass the file name with it's extension. 	
*/

//	1. opening a file

	FILE *file;
	
	file = fopen("file_test5.txt", "r");
//	Since we are reading file so we should pass "r" as the file mode in the fopen function.
	
//	2. Now we need a char variable which will hold the character read by getc() function.
//	To read the complete file we need to use the a while loop upto EOF.
	char ch;
	do{

		ch = fgetc(file);
		// get single character at a time.
		printf("%c", ch);		
	}while(ch != EOF);
	
//	3. close the file.
	fclose(file);
	
	printf("\n\nFile reading has been completed!");
}
