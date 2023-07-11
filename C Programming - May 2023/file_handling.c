#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE_LENGTH	1024
/*
	int  *p = variable address
	int **p = single pointer variable

	*/


void main() {

	FILE* file = NULL;
	char string[MAX_LINE_LENGTH] = {'\0'};
	// since fopen_s will 
	errno_t err = fopen_s(&file, "test.txt", "r");

	printf("Current Error Code: %d\n", err);

	if (err) {
		perror("Unable to Open file: ");
		exit(1);
	}

	// if no error then we will open read the file

	// reading the file until we don't reach at the end of the file.
	while (1) {

		fgets(string, MAX_LINE_LENGTH, file);

		printf("%s", string);

		if (feof(file)) break;
		// if we reach at the end of the file then break the loop.
	}

}