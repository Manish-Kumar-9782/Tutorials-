#include<stdio.h>
#include<string.h>

void main(){
	
	FILE *file;
	char string[100] = {'\0'};
	
	file = fopen("file_handle2.txt", "r");
	
//	we can read with three different function.
/*
	1. fscanf()
	2. fgetc()
	3. fgets()
*/

//	1. method to read file by using %s format specifier.

//	fscanf(file, "%s", &string);
//  printf("%s", string);


// 2. method to read whole file by using %[] 'edit format conversion'
//	fscanf(file, "%[]", &string);
//	printf("%s", string);
	

// 3. mehtod to read file by using %c format specifier.

	char ch;
//	fscanf(file, "%c", &ch);
//		
//	printf("%c", ch);
	
	// Note: since %c will only read single character at a time so we need to use do_while or while loop.
	int i=0;
	int eof;
	do{
	
		eof = fscanf(file, "%c", &ch);
		
//		puttiing the ch char into string
		string[i] = ch;
		i++;
		
	}while(eof != EOF);
	
//	EOF: end of file
	
	printf("%s", string);
	
	fclose(file);
	
	printf("\n\nfile reading is completed!");
}




