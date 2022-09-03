#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>


#define BOOK "books.csv"
// to control the position of the cursor: 
// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


          
// our new data type

//

/*
	required data types for library management
	
	-> Date -- date(day:month:year)
	-> Time -- time(hour:min:sec)
	-> Book -- book(title,subject,page,chapters,author,publisher,price)
	-> Student -- student(name, id/roll, class, age, stream, address)
	-> Address -- address(plot no, street/landmark, town,city,district,state,country,pincode)
	-> Department -- department(dep_sub, no_teacher, no_student)
	
	required function.
	
	-> add book.
	-> remove book.
	-> issue a book.
	-> return a book.
	-> view record.	
*/

typedef struct Date{
	// Date -- date(day:month:year)
	int day;
	int month;
	int year;
}date;

typedef struct Time{
	// Time -- time(hour:min:sec)
	int hour;
	int min;
	int sec;
}time;

typedef struct Book{
	//Book -- book(title,subject,page,chapters,author,publisher,price)
	char title[30];
	char subject[20];
	char author[20];
	char publisher[20];
	int page;
	int chapters;
	float price;
}book;

typedef struct Address{
	// address(plot no, street/landmark, town,city,district,state,country,pincode)
	int plot_no;
	char street_landmark[20];
	char town[20];
	char city[20];
	char district[20];
	char state[20];
	char country[20];
	int pincode; 
}adrs;

typedef struct Student{
	// Student -- student(name, id/roll, class, age, stream, address)
	char name[20];
	char stream[20];
	adrs address;
	int id;
	int std;
	int age;
}stud;

typedef struct Department{
	// Department -- department(dep_sub, no_teacher, no_student)
	char dept_subject[20];
	int no_teachers;
	int no_students;	
}dept;

/*
	required function.
	-> add book.
	-> remove book.
	-> issue a book.
	-> return a book.
	-> view record.	
	
	ctime()
	Now we will declare all the required function.
*/

void add_book(); // here book is data type of struct Book
void remove_book(book); 
void issue_book(stud, book, date, time, adrs);
void return_book(stud, book, date, time);



// printing funciton to print/show/display our new user-defined data types.
void print_stud(stud);
void print_date(date);
void print_time(time);
void print_book(book);
void print_adrs(adrs);
void print_dept(dept);

void write_book_header();

void scan_book(book*);
void view_books_record();
/*
	here arguments types
	book: to represent a book data type
	date: to represent a date data type
	time: to represent a time data type
	stud: to represent a student data type.
	adrs: to represent a address data type.
*/

//	some extra funciton
void pirnt_seprator(); // to print the seprator line
void show_main_options(); // to show the main options

//=========================================================================//
//=========================================================================//
void main(){
	bool True = true;
	bool False = false;
	int i = 0;
	char ch;
	
	COORD c;
	c.X = 20;
	c.Y = 21;
	
	printf("%40s Welcome To Library Management\n", " ");
	
	print_seprator(); // add  seprator
	show_main_options(); // to show the main options
	print_seprator(); // add seoratir
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
	ch = getch();
	printf("\nselected option: %c", ch);
	getch(); // to hold our input 
	system("cls"); // to clear the screen
	
	if(ch == '1'){
		
		printf("%40s Add a book section\n", " ");
//		------------------------------------------------------ //
		pirnt_seprator();
//		------------------------------------------------------ //
		add_book();
	}
	else if(ch == '2'){
		printf("remove a book section");
	}
	else if(ch == '3'){
		printf("Issue a book section");
	}
	else if(ch == '4'){
		printf("Return a book section");
	}
	else if (ch == '5'){
		printf("view book records");
	}
	else{
		printf("Invalid Selection!");
	}
}
//=========================================================================//
//=========================================================================//

//==================Scannig functions===============================//

void write_book_header(){
//	 Book -- book(title,subject,page,chapters,author,publisher,price)
	FILE *file = NULL;
	file = fopen(BOOK, "r");
	
	if(file == NULL){
//		if file is not found then we need to create one file with predefined header.
		file = fopen("books.csv", "w");
		fprintf(file, "Title,Subject,Page,Chapters,Author,Publisher,Price\n");
		fclose(file);
	}
	else{
		fclose(file);
	}
	
}

void scan_book(book *bk){
	// Book -- book(title,subject,page,chapters,author,publisher,price)
	printf("Enter Book Title: ");
	gets(bk->title);
	
	printf("Enter Book Subject: ");
	gets(bk->subject);
	
	printf("Enter Book Author: ");
	gets(bk->author);
	
	printf("Enter Book Publisher: ");
	gets(bk->publisher);
	
	printf("Enter Book price: ");
	scanf("%f", &bk->price);
	
	printf("Enter Book Page: ");
	scanf("%d", &bk->page);
	
	printf("Enter Book Chapters: ");
	scanf("%d", &bk->chapters);
	
	
	print_book(*bk);
}


//================================PRINTING FUNCTION FOR NEW DATA TYPES ================================

void print_stud(stud st){
	// Student -- student(name, id/roll, class, age, stream, address)
	printf("Name:\t%s", st.name);
	printf("Stream:\t%s", st.stream);
	printf("Class:\t%d",st.std);
	printf("Age:\t%d",st.age);
	printf("Id:\t%d", st.id);
//	print_adrs(st.address);
	
}

void print_date(date dt){
	printf("%d-%d-%d",dt.day,dt.month,dt.year);
}

void print_time(time tt){
	printf("%d:%d:%d",tt.hour,tt.min,tt.sec);
}

void print_book(book bk){
	// Book -- book(title,subject,page,chapters,author,publisher,price)
	printf("Title:\t%s\n", bk.title);
	printf("Subject:\t%s\n", bk.subject);
	printf("Page:\t%d\n", bk.page);
	printf("Price:\t%f\n",bk.price);
	printf("Chapters:\t%d\n", bk.chapters);
	printf("Author:\t%s\n", bk.author);
	printf("Publisher:\t%s\n", bk.publisher);
}

void print_adrs(adrs adr){
	// 	-> Address -- address(plot no, street/landmark, town,city,district,state,country,pincode)

	printf("Plot No:\t%s\n", adr.plot_no);
	printf("Street:\t%s\n", adr.street_landmark);
	printf("Town:\t%s\n", adr.town);
	printf("City:\t%s\n", adr.city);
	printf("District:\t%s\n", adr.district);
	printf("State:\t%s\n", adr.state);
	printf("Country:\t%s\n", adr.country);
	printf("Pincode:\t%s\n", adr.pincode);	
}

void print_dept(dept dp){
	// Department -- department(dep_sub, no_teacher, no_student)
	printf("Department Subject:\t%s\n", dp.dept_subject);
	printf("Department No of Teachers:\t%s\n", dp.no_teachers);
	printf("Department No of Students:\t%s\n", dp.no_students);
}

//================================ Library Functions ================================//

void add_book(){
	char ch;
	FILE *file = NULL;
	file = fopen(BOOK,"r");
	printf("file pointer values: %p", file);
	if(file == NULL){
		
		printf("\nBook database is not found...!");
		printf("\nCreating a New Book database...!");
		write_book_header();
//		This function will create a book.csv database.
		printf("\nDatabase Created!   press any to continue....");
		ch = getch();
		add_book();
	}
	else{
		fclose(file);
//		file close since it was opened in reading mode.
//	 Book -- book(title,subject,page,chapters,author,publisher,price)
		printf("\nAdding book information:\n");
		file = fopen(BOOK,"a");
		book bk;
		scan_book(&bk);
		
		fprintf(file, "%s,%s,%d,%d,%s,%s,%f\n", 
					bk.title, bk.subject,bk.page,bk.chapters,
					bk.author,bk.publisher,bk.price); 
		fclose(file);
		printf("file data has been saved!");
	}
}

void view_books_record(){
	
//	first clear the screen
	system("cls");
	
//	Now print the Title of the view
	printf("%45s Library Book Record", "");
	
//	Now we n
}


//================================ Extra Functions ================================//

void print_seprator(){
	for(i=0; i<25; i++){
		printf("----");
//		adding a book
		}
	printf("\n\n");
}

void show_main_options(){
	
	printf("1. Add a book\n");
	printf("2. Remove a book\n");
	printf("3. Issue a book\n");
	printf("4. Return a book\n");
	
	for(i=0; i<15; i++){
		printf("\n");
	}
	
	printf("Select an option: \n"); 
}
