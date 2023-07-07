#include<stdio.h>


void displayHeader(char[][15], char[][6], int);
void displayMarks(char[30], int[5]);

const char spaccing[] = "%-15s";
const char dspace[] = "%-15d";

void main() {

	char ft_string[][6] = { {"%20s |"}, {"%-10s"}, {"%-10s"}, {"%-10s"},{"%-10s"},{"%-10s"} };

	char Subjects[5][15] = { "Hindi","English","Physics","Math","Chemistry" };

	char Students[5][30] = { "Bhavya", "Kuldeep","Kush", "Dinesh", "Karan" };

	// array for number per student
	int numbers[5][5] = {
		{15, 95, 65, 60, 18 },
		{84, 63, 78, 35, 78},
		{63, 14, 94, 40, 42},
		{30, 34, 47, 89, 91},
		{28, 32, 87, 36, 18} };


	displayHeader(Subjects, ft_string, 5);
	printf("------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		displayMarks(Students[i], numbers[i], 5);
	}
}



void displayHeader(char subs[][15], const char fts[][6], int size) {


	printf(spaccing, "Student");

	for (int i = 0; i < size; i++) {
		printf(spaccing, subs[i]);
	}

	printf("\n");
}

void displayMarks(char student[30], int marks[5], int size){

	printf(spaccing, student);

	for (int i = 0; i < size; i++) {
		printf(dspace, marks[i]);
	}

	printf("\n");
}