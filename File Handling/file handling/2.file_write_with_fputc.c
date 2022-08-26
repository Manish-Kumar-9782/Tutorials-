#include<stdio.h>
#include<string.h>
/*
In this section we will see how to use the fputc() file writing function
to write something on the file.

Note: if we want to control over the format of the output string, then we 
should consider this function.

fputc()	writes a character into the file

*/

// int fputc(int c, FILE *stream)  

/*
	fputc() takes two arguments
	
	1. first argument as the charcter which need to put in the file.
	2. second argument as the file pointer in which file that charcter will be put.
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
	FILE  *file;
	
	file = fopen("file_test2.txt", "w");
		
//	Since fopen funciton will return an address of the file 
// so we have stored the returen file's address in file pointer.

// Now we will use the fputc() function to write one character at a time.

//	suppose that we have a string

	char string[70] = "Hello this file writing by using the fputc function.";
	char ch; // to hold the single character
	
//	Now we want to write a single character at once then we can use fputc.

// In this condition we can use while or for loop.
// but here we will use the while loop

//	we will run the while loop until we don't get the null-character '\n'
	int i=0;
	do{
		ch = string[i]; // get the character in the ch.
		
		fputc(ch, file);
		// putting the each single character from the string.
		i++;
		
	}
	while(ch != '\0');
//	end the loop if reach at the end of the string.

// message after writing the file.

	fclose(file); // closing the file.

	printf("file writing has been completed!");
}

