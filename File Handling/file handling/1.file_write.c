#include<stdio.h>
#include<string.h>
/*
1	fopen()	opens new or existing file
2	fprintf()	write data into the file
3	fscanf()	reads data from the file
4	fputc()	writes a character into the file
5	fgetc()	reads a character from file
	fputs() to write a complete string
	fgets() to read a coplete string.
6	fclose()	closes the file
7	fseek()	sets the file pointer to given position
8	fputw()	writes an integer to file
9	fgetw()	reads an integer from file
10	ftell()	returns current position
11	rewind()	sets the file pointer to the beginning of the file
*/

/*
file mode
r	:	opens a text file in read mode
w	:	opens a text file in write mode
a	:	opens a text file in append mode
r+	:	opens a text file in read and write mode
w+	:	opens a text file in read and write mode
a+	:	opens a text file in read and write mode
rb	:	opens a binary file in read mode
wb	:	opens a binary file in write mode
ab	:	opens a binary file in append mode
rb+	:	opens a binary file in read and write mode
wb+	:	opens a binary file in read and write mode
ab+	:	opens a binary file in read and write mode
*/

void main(){
	
//	Steps to open and write a file 
//	1. open a file by using the fopen() function.

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
	
	file = fopen("file_test1.txt", "w");
	
//	Since fopen funciton will return an address of the file 
// so we have stored the returen file's address in file pointer.

//	2. Now we need to write some test in this file.
//	There are fprintf(), fputc(), fputs() function to write the data into the file.
//	we will see them one by one.

//	3. For now we will use fprintf() function.

//	int fprintf(FILE *stream, const char *format [, argument, ...])

/* fprintf takes two main argument   

	1. first argument is file pointer
	2. second argument same as the printf() functions arguments.
	
	we can pass formatted string in this.
*/

	fprintf(file, "hello this is the test of file write mode.");
	
//	Note: after each complete read or write operation we must close the file.

	fclose(file); // closing the file by using the fclose() function.

//	last message on screen:
	printf("file writing has been completed!");
// Note: Now if we open the file "file_test1.txt" we will have the passed string in our file.
}


