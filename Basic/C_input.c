// C Code to explain why not
// clearing the input buffer
// causes undesired outputs
#include<stdio.h>
int main()
{
	char str[80], ch;
	
	// Scan input from user -
	// GeeksforGeeks for example
	scanf("%s", str);
	
	// Scan character from user-
	// 'a' for example
	ch = getchar();
	
	// Printing character array,
	// prints “GeeksforGeeks”)
	printf("%s\n", str);
	
	// This does not print
	// character 'a'
	printf("%c", ch);
	
	return 0;
}

/*
	In this section we have encountered the preoccupied buffer problem which need 
	to be clear.
*/ 	

