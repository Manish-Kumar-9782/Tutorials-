#include<stdio.h>

void displayRow(int);

void main() {

	int numberOfEmpoyees[] = { 12,23,35,20,11 };
	printf("|\n|\n");
	for (int i = 0; i < 5;i++) {
		displayRow(numberOfEmpoyees[i],0,1);
		displayRow(numberOfEmpoyees[i],1,1);
		displayRow(numberOfEmpoyees[i],0,1);
		printf("\n\n");
	}

}

void displayRow(int count,int display_count,int new_line,int show_label) {

	int offset = 10;

	printf("|");
	for (int i = 0; i <= count+offset; i++) {
		
		// writing inline code 
		if (i < offset) {
			printf(" ");
		}
		else if (i == offset) {
			printf("|");
		}
		else {
			printf("*");
		}
	}
	if (display_count) printf("(%d)", count);
	if (new_line) printf("\n");
}