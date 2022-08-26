#include<stdio.h>
#include<string.h>

/*
	In this section we will write file by using the fputs function.
	with this function we can write the complete string at once.
	
	// int fputs(const char *s, FILE *stream)  
	
	fputs function takes two arguments.
	
	1. first argument: a string which need to be written in the file.
	2. second argument: a file pointer in which we our string will be written.
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

//	opening a file
	FILE *file;
	
	file = fopen("file_test3.txt", "w");
//	opening a file in writing mode.

//	Now we wil use the fputs function.

	char string[80] = "This file has been written by using the fputs funciton.";
	
	fputs(string, file); 
//	writing the complete string at once.

	fclose(file); // closing the file.
	
//	meassgae after writing the file.
	
	
	printf("file writing has been completed!");
}
