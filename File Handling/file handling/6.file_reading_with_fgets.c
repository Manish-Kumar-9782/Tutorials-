#include<stdio.h>
#include<string.h>

/*
	In this section we will read a file by uisng the fgets() function.
	
	char* fgets(char *s, int n, FILE *stream)  
	
	It takes:
	
	1. first argument: 
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
	
	file = fopen("file_test6.txt", "r");
//	Since we are reading file so we should pass "r" as the file mode in the fopen function.
	
	char string[80];
	
//	
	fgets(string,80,file);
//	store the string upto 80bytes line into the 'string' char array.
	printf("%s", string);
//	print the string.
	
	fclose(file);
//	close the file.
}



