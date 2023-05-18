#include<stdio.h>
#include<string.h>
/*
	In this section we will store the data of books details using 
	structure and file handling.
	
	// book.csv contains these fields.
	fields: Title,Subject,Page,Chapters,Author,Publisher,Price
*/

struct Book{
	int id;
	int deleted;
	char title[30]; // fields[0]
	char subject[30]; // fields[1]
	char pages[30]; //  fields[2]
	char chapters[30]; // fields[3]
	char author[30]; // fields[4]
	char publisher[30]; // fields[5]
	char price[30]; // fields[6]
};

struct BookFormat{
	int id;
	char title[6]; // fields[0]
	char subject[6]; // fields[1]
	char pages[6]; //  fields[2]
	char chapters[6]; // fields[3]
	char author[6]; // fields[4]
	char publisher[6]; // fields[5]
	char price[6]; // fields[6]
};

struct BookFormat bkF = {"%-10d","%-20s", "%-20s","%-10s","%-10s","%-15s","%-15s","%-5s"};

void getFields(FILE*, char[][30]);
void printRow(char[][30],char[][6],int); 
void printSep(char, int);
void getBooks(FILE*, struct Book[], int);
void assignBook(struct Book*, char[][30], int i); // a function to assign all book details.
void printBook(struct Book, struct BookFormat);
void addBook(char fileName[]);
void deleteBook(int bookId, struct Book*, int len);
void saveBooks(char[],struct Book[], int);
void writeHeader(FILE *file, char header[]);
void saveBook(FILE*, struct Book, char format[]);

void main(){
	
	// a 2d array to store all the fields contained in book.csv file.
	// an array of Book struture.
	char fields[7][30] = {'\0'};
	struct Book books[4] = {'\0'}; // it willl hold all books
	char format[7][6] = {"%-20s", "%-20s","%-10s","%-10s","%-20s","%-20s","%-10s"};
	
	FILE *file = fopen("books.csv","r");
	
	getFields(file, fields);

	getBooks(file,books, 4);
	// printf("book 1 title: %s", books[1].title);	
	int i=0;
	printRow(fields,format,8);
	printSep('=',80);
	// printf("Title is %-10s", books[0].title);
	for(i=0; i<4; i++){
		printBook(books[i], bkF);
	}

	// addBook("books.csv");
	int bookId = -1;
	printf("Enter Book id to delete: ");
	scanf("%d", &bookId);
	deleteBook(bookId,books, 4);
	saveBooks("bks.csv", books,4);

	fclose(file);
}

void getFields(FILE *file, char fields[][30]){
	
	int i = 0, j=0,k=0; 
	char ch='\0';
	for(i=0; i<300; i++){
		
		fscanf(file,"%c",&ch);
//		printf("%c",ch);
		
		if(ch != '\n'){
			if(ch != ','){
				fields[j][k] = ch;
				k++;
			}else{
				j++; // it will moniter the record columns
				k=0; // it will moniter the each char index in each column.
			}
		}
		else{
			// break the loop at the end of the current line
			break;
		}
	}
}

void printRow(char row[][30],char format[][6], int n){
	int i=0;
	
	for(i=0; i<n; i++){
		printf(format[i], row[i]);
	}
	printf("\n");
}

void printSep(char ch, int count){
	int i=0;
	for(i=0;i<count; i++){
		printf("%c",ch);
	}
	printf("\n");
}

void assignBook(struct Book *book, char data[][30], int i){
	//book.title, book.subject, book.pages, book.chapters, book.author, book.publisher, 
	// book.price.
	strcpy(book->title, data[0]);
	strcpy(book->subject ,data[1]);
	strcpy(book->pages , data[2]);
	strcpy(book->chapters , data[3]);
	strcpy(book->author , data[4]);
	strcpy(book->publisher , data[5]);
	strcpy(book->price , data[6]);
	book->id = i;

	// printf("book title: %s", book.title);
}

void getBooks(FILE *file, struct Book books[], int n){
	
	char fields[7][30] = {'\0'};
	// char format[7][6] = {"%-20s", "%-20s","%-10s","%-10s","%-20s","%-20s","%-10s"};
	// this filed will hold the single row for a moment until we 
	// don't store all the data into the books structure array.
	int i =0;
	for(i=0; i<n; i++){
		getFields(file, fields);
		// printRow(fields,format,7);
		assignBook(&books[i], fields, i);
		// printBook(books[i], bkF);
	}
	
}

void printBook(struct Book bk, struct BookFormat bkf){
	printf(bkf.id, bk.id);
	printf(bkf.title, bk.title);
	printf(bkf.author, bk.author);
	printf(bkf.subject, bk.subject);
	printf(bkf.pages, bk.pages);
	printf(bkf.chapters, bk.chapters);
	printf(bkf.publisher, bk.publisher);
	printf(bkf.price, bk.price);
	printf("\n");
	printSep('-',80);
}

void addBook(char filename[]){
// this function will add a book to the book.csv file.
// to write data to the file we need printf function.
	struct Book bk;
	FILE *file = fopen(filename, "a");
	
	printf("Enter book title: ");
	scanf("%s",&bk.title);

	printf("Enter book subject: ");
	scanf("%s",&bk.subject);

	printf("Enter book author: ");
	scanf("%s",&bk.author);
	
	printf("Enter book publisher: ");
	scanf("%s",&bk.publisher);
	
	printf("Enter book pages: ");
	scanf("%s",&bk.pages);
	
	printf("Enter book price:");
	scanf("%s",&bk.price);
	
	printf("Enter book chapters: ");
	scanf("%s",&bk.chapters);

	fprintf(file, "%s,%s,%s,%s,%s,%s,%s\n",bk.title,bk.subject,bk.pages,bk.chapters,bk.author,bk.publisher,bk.price);
}


void deleteBook(int bookId, struct Book *books, int len){

	int i=0;
	for(i=0; i<len; i++){
		struct Book *bk = &books[i];
		if(bk->id == bookId){
			bk->deleted = 1;
			printf("Book %d  Deleted: %d\n", bookId, bk->deleted);
		}
	}
}

void writeHeader(FILE *file, char header[]){
	fprintf(file, "%s", header);
}

void saveBook(FILE *file, struct Book bk ,char format[]){
	/** title, subject, pages, chapters, author, publisher, price*/
	fprintf(file, format, bk.title, bk.subject, bk.pages, bk.chapters, bk.author, bk.publisher, bk.price);
}

void saveBooks(char fileName[],struct Book books[], int n){

	int i=0;
	FILE *file = fopen(fileName,"w");
	writeHeader(file, "title,subject,pages,chapters,author,publisher,price\n");
	for(i=0; i<n; i++){
		struct Book bk = books[i];
		if(bk.deleted != 1){
			saveBook(file,bk, "%s,%s,%s,%s,%s,%s,%s\n");
		}
	}
}



