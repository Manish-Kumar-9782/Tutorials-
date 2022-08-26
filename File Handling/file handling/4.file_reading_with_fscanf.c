#include<stdio.h>
#include<string.h>

/*
	In this section we will read file by using the fscanf() function.
	
	int fscanf(FILE *stream, const char *format [, argument, ...]) 
	
	1. first argument: it is the file pointer which need to be scanned.
	2. second argument: it is same as the scanf() function argument.

	Note: this function returned EOF and the end of the file.
*/


/*
	We will read file using three different methods.
	1. reading file with %s format specifier.
	2. reading file with %[] edit format conversion.(efc)
	3. reading file with %c format specifier. 
*/

void read_with_pr_s(FILE *file);
// read with percent s (%s) format specifier.

void read_with_pr_efc(FILE *file);
// read with percent [] (%[]) edit format conversion

void read_with_pr_c(FILE *file);
// read with percent c (%c) format specifier

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
	
	file = fopen("file_test4.txt", "r");
//	Since we are reading file so we should pass "r" as the file mode in the fopen function.

/*	2. Now we need to scanf the file by using the fscanf but 
before that we need a variable in which we will store our string..

	Note: we can read the file with both %c and %s format specifier.
*/	

	
//	A variable to stored the characters scanned from the file.
	
//	3. scan the file.

/*===============================================================*/
// i. reading method by using the %s format specifier.

// -------------------------------	
//	read_with_pr_s(file);
// -------------------------------		

/*	Note: There is a problem reading with %s format specifier.
		It will terminate the reading if it get any blank whitespace ' '.

	Solution: as alternative we can use 'edit set conversion code' "%[..]" 
			format to read everything from the file.
*/ 

/*===============================================================*/

// comment the above fscanf while using the below fscanf format

//	ii. reading file by using the edit format conversion method.
	
// -------------------------------	
//	read_with_pr_efc(file);
// -------------------------------	

/*===============================================================*/

//	iii. reading fiel by using the %c format specifier

//	Since %c will only allow use read only one character at a time.
// To read the whole line we need to use while loop
	
// -------------------------------	
	read_with_pr_c(file);
// -------------------------------	

/*===============================================================*/

	
	printf("\n\nFile reading has been completed!");
}

/*==============================================================*/
// read with percent s (%s) format specifier.
void read_with_pr_s(FILE *file){
	char string[80] = {'\0'}; 
	fscanf(file, "%s", string);
	printf("%s", string);
	fclose(file);
}


// read with percent [] (%[]) edit format conversion
void read_with_pr_efc(FILE *file){
	char string[80] = {'\0'}; 
	fscanf(file, "%[]", string);
	printf("%s", string);
	// %[] will allow us to read all the string.
	fclose(file);
}


// read with percent c (%c) format specifier
void read_with_pr_c(FILE *file){
	char ch;
	int eof;
	do{
		eof = fscanf(file,"%c", &ch);
//		get the character from strem buffer
		printf("%c",ch);
//		print the ch on the screen.
		
	}
	while(eof != EOF);
//	here EOF is used for end of file.
	fclose(file);
}



