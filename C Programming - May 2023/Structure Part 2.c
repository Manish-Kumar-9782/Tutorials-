#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
	char title[30];
	char author[30];
	int pages;
	float price;
};

struct Book* createBook(char[30], char[30], int, float);

struct Book* insertBook();

void displayBook(struct Book*);

void main() {

	struct Book* book = insertBook();

	printf("\n--------------------\n");
	displayBook(book);

}

struct Book* createBook(char title[30], char author[30], int pages, float price) {

	struct Book *book = (struct Book*)malloc(sizeof(struct Book));

	strcpy_s(book->title, 30, title);
	strcpy_s(book->author, 30, author);
	
	book->pages = pages;
	book->price = price;
	
	return book;
}

struct Book* insertBook() {

	char title[30] = {"\0"};
	char author[30] = { "\0" };

	int pages = 0;
	float price = 0;

	printf("Enter Book Title: ");
	gets_s(title, 30);

	printf("Enter Book Author Name: ");
	gets_s(author, 30);

	printf("Enter Book Pages: ");
	scanf_s("%d", &pages);

	printf("Enter Book Price: ");
	scanf_s("%f", &price);

	return createBook(title, author, pages, price);
}

void displayBook(struct Book *book) {
	
	printf("Book Name: %s\n", book->title);
	printf("Book Author: %s\n", book->author);
	printf("Book Pages: %d\n", book->pages);
	printf("Book Price: %f\n", book->price);
}