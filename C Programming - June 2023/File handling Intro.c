#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	fopen, fopen_s : to open a file
	fclose() : to close a file.

	fgets()
	fgetc()
	fputc()
	fputs()

	fscanf(), fscanf_s()
	fprintf(), fprintf_s()

	feof(): end of file.

	perror(): error handling

	filemode: 
		
		"r": file reading mode
		"w": file writing mode
		"a": file append mode
		"b": file read in binary mode.
		"r+": read, read and write
		"w+": write read and write
		"a+": append read and write

		int var;
		int *var1;
		int **var2;

		*var1 = &var;
		**var2 = &var1;

*/

int main() {

	FILE* file = NULL;
	errno_t err = fopen_s(&file,"arrayx.c", "r");

	
	if (!err) {
		char ch = '\0';
		while (!feof(file)) {
			fscanf_s(file, "%c", &ch);
			printf("%c", ch);
		}
	}
	else {
		perror("fopen failed");
		exit(1);
	}

	fclose(file);
	return 0;
}