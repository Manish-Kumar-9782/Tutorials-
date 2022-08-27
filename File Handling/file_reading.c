#include<stdio.h>

/*
fopen()	opens new or existing file
//fscanf()	reads data from the file
fgets()

reading mode: 'r'

*/

void main(){
	
//	steps in order
	
	char file[50];
	
//	1.first make a file pointer

	FILE *fp; // a file pointer to hold the file variable address.
	
//	2. reading a file by using the reading mode 'r'
	fp = fopen("file_handle2.txt", "r");
	
//	3. to read a file we need to use fscanf()

//	fscanf(fp,"%s");
//	printf("%s",a)
	
	char ch;

	fgets(file,50,fp);
	
	printf("%s", file);
	
	fclose(fp);
	
}
