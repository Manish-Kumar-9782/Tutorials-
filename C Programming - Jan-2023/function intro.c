#include<stdio.h>


void show_pattern(int);

void main() {

	int isNumber = 1;
	while (isNumber) {
		
		int size = 0;
		printf("Enter the size of the pattern: ");
		scanf_s("%d", &size);

		show_pattern(size);
	}
}

