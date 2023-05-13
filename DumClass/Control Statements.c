#include<stdio.h>

void main() {
	
	// "\0" null character
	int i = 0;
	char ch = "\0";
	ch = '1';
	switch (ch) {
	case '1':
			printf("This is case 1");
			break; // 
	case '2':
			printf("This is case 2");
			break;
	case '3':
			printf("This is case 3");
			break;
		default:
			printf("This is default case");

	}
}