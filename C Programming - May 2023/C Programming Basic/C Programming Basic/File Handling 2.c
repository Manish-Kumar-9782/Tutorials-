#include<stdio.h>
#include<stdlib.h>

typedef int age;
typedef int error_t;

struct Book {
	char title[30];
	char author[30];
	int pages;
	float price;
};

void simple_file_writing();
void formated_file_writing();

// In this we will work on the file writing mode.
void main() {
	// to write a file, first we need to open that file into "w" writing mode.
	//simple_file_writing();
	formated_file_writing();
}

void simple_file_writing() {
	FILE* file = NULL;
	errno_t err = fopen_s(&file, "firstFile.txt", "w");

	if (err) {
		perror("Unable to open file: ");
		exit(1);
	}

	fprintf(file, "Hello how are you..");


	fclose(file);
}

void formated_file_writing() {
	FILE* file = NULL;
	errno_t err = fopen_s(&file, "data.csv", "w");

	struct Book bk = { "How to Learn C Programming", "C Programming", 120, 456.7 };

	if (err) {
		perror("Unable to open file: ");
		exit(1);
	}

	fprintf(file, "%s,%s,%d,%f",bk.title, bk.author, bk.pages, bk.price);

	printf("Data Has been successfully saved to file.");
	fclose(file);
}