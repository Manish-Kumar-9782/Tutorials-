#include<stdio.h>
#include<string.h>
/*
1	fopen()	opens new or existing file
2	fprintf()	write data into the file
3	fscanf()	reads data from the file
4	fputc()	writes a character into the file
5	fgetc()	reads a character from file
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
	
	FILE *fp;
	
	char ch;
	
	fp = fopen("file_handle2.txt","w");
	
	char greet[20] ="Hello World!";
	
	int size = strlen(greet);
	int i =0;
	
//	for(i=0; i<size; i++){
//		
//		fputc(greet[i], fp);
//		
//	}

	fputs(greet, fp);
	fclose(fp);
	
}
