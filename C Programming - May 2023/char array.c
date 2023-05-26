#include<stdio.h>

void main() {
	// Now we will work on the char array.
	char name[10];  // garbage value
	
	printf("\n======================================\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", name[i]);
	}
	printf("\n======================================\n");

	// x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-//
	
	// Now we will make another array with initializer list.
	char namex[10]={'\0'};  // \0: null character
	printf("\n======================================\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", namex[i]);
	}
	printf("\n======================================\n");

	// x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-//

	// Use of null character: 
	// it is used to store empty character and also it used to interpret that 
	// our string has been finished. we use this null character in our algorithm to
	// find out the end of the string.

	// string without null character.
	// suppose we have 15 character string and only few of them are filled 
	// with character.
	char string_no_null[15]; // \0: null character
	printf("\nWith out Null Character: ");
	char ch='\0';
	int i = 0;
	while (ch != ' ') {
		scanf_s("%c", &ch);
		string_no_null[i] = ch;
		i++;
	}


	printf("\n======================================\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", string_no_null[i]);
	}
	printf("\n======================================\n");

	//-x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x--x-x-//
	char string_no_nullx[15] = { '\0' }; // \0: null character
	printf("\nWith Null Character: ");
	char chx = '\0';
	int ix = 0;
	while (chx != ' ') {
		scanf_s("%c", &chx);
		string_no_nullx[ix] = chx;
		ix++;
	}


	printf("\n======================================\n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", string_no_nullx[i]);
	}
	printf("\n======================================\n");


	// reading full string with scanf_s inside while
	char my_name[15] = { '\0' }; // \0: null character
	char dummy[15];
	gets_s(dummy, 15);
	printf("\nWith Null Character: ");
	char chy = '\0';
	int iy = 0;

	while (chy != '\n') {
		scanf_s("%c", &chy);
		my_name[iy] = chy;
		iy++;
	}


	printf("\n======================================\n");
	for (int i = 0; i < 15; i++) {
		printf("%c", my_name[i]);
	}
	printf("\n======================================\n");
}