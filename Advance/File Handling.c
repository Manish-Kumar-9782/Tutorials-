#include<stdio.h>

/*
	In this section we will see how to work with files
	1. how to open  a file.
	2. read data from file.
	3. update file/ write some data to file.
	4. close file.
	
	fscanf() :  function to read data from file.
	fprintf():  function to write data to a file.
	fopen(): a fuction to open a file.
	fclose(): a function to close a file.
	
	*FILE : a file pointer which has the file reference in the memory
	this file pointer allow us to intract with the file.
	
	In this we need to store the file pointer inside the variable of FILE data type.
	
	fopen("filename", 'filemode'):
		filename: filename is a string which contains the relative of aboslute path
		of the file.
		
		filemode: file opening mode.
			r : reading mode.
			w : writeing mode. // if file not exist then it will crteate a new file
					// if file exist then it will rewrite all the content.
			a : append mode. // to add new data inside the file at the end of the file.
			r+ : for both read and write
			w+ : for both read and write.
			a+ : for both read and write but starts from at the end of the file.
			EOF: END OF FILE.
			 
*/

void main(){
	
	// first of all we open a file by using the fopen() funciton
	// this funciton returns a file pointer
	// so we need to store that file pointer inside the FILE type pointer variable.
	FILE *file = fopen("books.csv", "r");
	
	// now we will use fscanf function to read data from file.
	char data[300] = {'\0'};
	
	// reading 1st line
	fscanf(file,"%s",data);
	printf("%s\n", data);
				
	// reading 2nd line
	fscanf(file,"%s",data);
	printf("%s\n", data);
	
	// after doing our operation with file always close the file.
	fclose(file);
	
}
