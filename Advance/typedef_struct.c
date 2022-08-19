#include<stdio.h>

// typedef a keyword to make new user defined data type.

typedef struct Student{
	char name[16];
	int age;
	char graduation[7]; 
}stu;



typedef struct Date{
	int year;
	int month;
	int day;
}date;

typedef struct Book{
	char book_name[20];
	int pages;
	date publish_date;   // publish_date [year, month, day]
	char author_name[20];
};

// here stu is a alias name for our struct data type

void print_st();
void print_date();  // make a function to show the date of the book's publish date
void print_book();  // make a function to show the information of the book.

// Date format "day:month:year"

void main(){

	stu st1 = {"Manish", 26, "b.tech"};
	
	print_st(st1);

}

void print_st(struct Student st){
	
	printf("Name:\t\t%s\n", st.name);
	printf("Graduation:\t%s\n", st.graduation);
	printf("Age:\t\t%d\n", st.age);
	printf("\n---------------------------\n"); // for next student 
}




