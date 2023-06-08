#include<stdio.h>

#define PASSING_MARKS_PER_SUBJECT = 45
#define COLUMN_FORMAT = "%-15s"

/*
	Array of Subject Name
	Array of Student Names
	Array of Student Number Per Subject

*/

void print_columns(char col[][30], int size);
void print_column(char col[]);

void print_name(char name[]);
void print_numbers(int numbers[], int size);

// ========================================================================== //
const char column_format_s[] = "%-15s";
const char column_format_d[] = "%-15d";
void main() {

	

	char Subjects[5][30] = { "Hindi","English","Math","Science","Biology" };

	// Note: this kind array may have dynamics data
	// for now we only have 5 students.
	char Students[5][30] = { "Bhavya", "Kuldeep","Kush","Dinesh","Karan" };

	// array for number per student
	int numbers[5][5] = { 
		{15, 95, 65, 60, 18 },
		{84, 63, 78, 35, 78},
		{63, 14, 94, 40, 42},
		{30, 34, 47, 89, 91},
		{28, 32, 87, 36, 18} };

	//--------------------------------//
	print_column("Names");
	print_columns(Subjects, 5, 1);

	for (int i = 0; i < 5; i++) {
		print_name(Students[i]);
		print_numbers(numbers[i], 5, 1);
	}

}
// ========================================================================== //

void print_columns(char col[][30], int size, int newline) {

	for (int i = 0; i < size; i++) {
		printf(column_format_s, col[i]);
	}
	if (newline) printf("\n");
}

void print_numbers(int numbers[], int size, int newline) {
	for (int i = 0; i < size; i++) {
		printf(column_format_d, numbers[i]);
	}
	if (newline) printf("\n");
}

void print_name(char name[]) {
	printf(column_format_s, name);
}

void print_column(char col[]) {
	print_name(col);
}