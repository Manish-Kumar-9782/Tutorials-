#include<stdio.h>

// in this section we will make some new data type.

// Making a user-defined data type for Dates.
typedef struct Date{
	int year;
	int month;
	int day;
}date;

// Making a user-defined data type for Time.
typedef struct Time{
	int hour;
	int min;
	int sec;
}time;


typedef struct Book{
	
	char Title[20];
	char author[20];
	int pages;
	int chapters;
	
}book;


void print_date(date);
void print_time(time);
void print_book(book);

void main(){

	// initalization of struct based user-defined datat types.
	
	// Initialization of Date;
	date today_date = {2022, 8, 20};
	time current_time = {4,27,32};
	book book1 = {"The Great", "Saloni", 7665, 21};
	
	
	print_book(book1);
	print_date(today_date);
	print_time(current_time);
}

void print_date(date dt){
	
	printf("Date:[%d-%d-%d]", dt.day, dt.month, dt.year);
	printf("\n");
}

void print_time(time tt){
	printf("Time:[%d:%d:%d]", tt.hour, tt.min, tt.sec);
	printf("\n");
}

void print_book(book bk){
	printf("Title:\t\t%s\n", bk.Title);
	printf("Author:\t\t%s\n", bk.author);
	printf("Pages:\t\t%d\n", bk.pages);
	printf("Chapters:\t%d\n", bk.chapters);
	printf("\n");
}
