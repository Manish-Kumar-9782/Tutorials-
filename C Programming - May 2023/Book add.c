#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME "books.csv" 

struct Book {
	char title[30];
	char author[30];
	int pages;
	float price;
};

// given an alias name to struct Book
typedef struct Book BOOK;

void write_header(const char*, FILE*);

void write_book(BOOK bk, FILE*);

void main() {
	
	FILE* file = NULL;
	char ch = '\0';
	errno_t err = fopen_s(&file, FILE_NAME, "w");

	if (err) {
		perror("Unable to open File: ");
		exit(1);
	}

	// first of all we will put the heading

	write_header("Title,Author,Pages,Price\n", file);

	while (1) {

		printf("Do You Want to add Book (y/n): ");
		scanf_s("%c", &ch);

		if ((ch == 'q') || (ch == 'n')) break;

		if (ch == 'y') {

			BOOK bk;
			scanf_s("%c", &ch);
			printf("Enter Book Title: ");
			gets_s(bk.title, 30);

			printf("Enter Book Author: ");
			gets_s(bk.author, 30);

			printf("Enter Book Pages: ");
			scanf_s("%d", &bk.pages);

			printf("Enter Book Price: ");
			scanf_s("%f", &bk.price);

			write_book(bk, file);
		}

		
	}
	

	fclose(file);
}

void write_header(const char* header, FILE *file) {
	fprintf_s(file, "%s", header);
}

void write_book(BOOK bk, FILE* file) {

	fprintf_s(file, "%s,%s,%d,%f\n", bk.title, bk.author, bk.pages, bk.price);
}