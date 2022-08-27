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
	
	FILE *fp;  // FILE data type for file handling
	
	
	
	char ch;
	
	// first of all we will opean a file in write mode put some text in a file
	fp = fopen("file_handle2.txt","w");
	// here we have used the relative file address.
//	
	char greet[50] = "C is good! \nthis is file handling class";
	
	int size = strlen(greet);
	// strlen() is uesed to get the length of the string.
	int i =0;
	
//	for(i=0; i<size; i++){
//		
//		fputc(greet[i], fp);
//		// putting single character
//		
//	}

	fputs(greet, fp);
	fclose(fp);
	
}
