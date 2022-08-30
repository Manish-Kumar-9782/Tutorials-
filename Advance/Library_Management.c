#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

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
	
	Now we will declare all the required function.
*/

void add_book(book, date, time); // here book is data type of struct Book
void remove_book(book, date, time); 
void issue_book(stud, book, date, time, adrs);
void return_book(stud, book, date, time);



// printing funciton to print/show/display our new user-defined data types.
void print_stud(stud);
void print_date(date);
void print_time(time);
void print_book(book);
void print_adrs(adrs);
void print_dept(dept);


void scan_book(book);
/*
	here arguments types
	book: to represent a book data type
	date: to represent a date data type
	time: to represent a time data type
	stud: to represent a student data type.
	adrs: to represent a address data type.
*/

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
	
	for(i=0; i<25; i++){
		printf("----");
	}
	
	printf("\n1. Add a book\n");
	printf("2. Remove a book\n");
	printf("3. Issue a book\n");
	printf("4. Return a book\n");
	
	for(i=0; i<15; i++){
		printf("\n");
	}
	
	printf("Select an option: \n"); // 21
	

	
	printf("\n");
	for(i=0; i<25; i++){
		printf("----");
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
	ch = getch();
	printf("\nselected option: %c", ch);
	getch(); // to hold our input 
	system("cls"); // to clear the screen
	
	if(ch == '1'){
		
		printf("%40s Add a book section\n", " ");
			for(i=0; i<25; i++){
		printf("----");
	}
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
	else{
		printf("Invalid Selection!");
	}
}
//=========================================================================//
//=========================================================================//

//==================Scannig functions===============================//

void scan_book(book bk){
	// Book -- book(title,subject,page,chapters,author,publisher,price)
	printf("Enter Book Title: ");
	gets(bk.title);
	
	printf("Enter Book Subject: ");
	gets(bk.subject);
	
	printf("Enter Book Author: ");
	gets(bk.author);
	
	printf("Enter Book Publisher: ");
	gets(bk.publisher);
	
	printf("Enter Book price: ");
	scanf("%f", &bk.price);
	
	printf("Enter Book Page: ");
	scanf("%d", &bk.page);
	
	printf("Enter Book Chapters: ");
	scanf("%d", &bk.chapters);
	
	
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
	printf("Title:\t%s", bk.title);
	printf("Subject:\t%s", bk.subject);
	printf("Page:\t%d", bk.page);
	printf("Price:\t%f",bk.price);
	printf("Chapters:\t%d", bk.chapters);
	printf("Author:\t%s", bk.author);
	printf("Publisher:\t%s", bk.publisher);
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



