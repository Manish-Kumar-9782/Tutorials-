#include<stdio.h>

// Now we will 
void print_margin(char,int, char[],int);
void displayRow(int, int, int);

void main() {

	int numberOfEmpoyees[] = { 12,23,35,20,11 };

	for (int i = 0; i < 5;i++) {
		
		print_margin(' ', 10, "", 0);
		displayRow(numberOfEmpoyees[i], 0, 1);
		
		print_margin(' ', 10, "Group-x", 7);
		displayRow(numberOfEmpoyees[i], 1, 1);
		
		print_margin(' ', 10, "", 0);
		displayRow(numberOfEmpoyees[i], 0, 1);

		print_margin(' ', 10, "", 0);
		printf("\n");
	}
}

void print_margin(const char ch,int margin_len,char label[], int label_len) {

	printf("|");

	int spaces = margin_len - label_len;
	int label_characters=0;

	if (spaces < 0) {
		spaces = margin_len;
		label_characters = 0;
	}
	else {
		label_characters = margin_len - spaces;
	}

	for (int i = 0, j=0; i < spaces+ label_characters; i++) {
		if (i < spaces) {
			printf("%c", ch);
		}
		else {
			printf("%c", label[j]);
			j++;
		}
	}
	printf("|");

}

void displayRow(int count, int display_count, int new_line) {

	for (int i = 0; i <= count; i++) {
		// writing inline code 
		printf("*");
	}
	if (display_count) printf("(%d)", count);
	if (new_line) printf("\n");
}