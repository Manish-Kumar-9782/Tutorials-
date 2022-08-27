#include<stdio.h>
#include<string.h>

typedef struct Student{
	// Student -- student(name, id/roll, class, age, stream, address)
	char name[20];
	char stream[20];
	int id;
	int std;
	int age;
	
}stud;

void write_student_info(stud);
void write_student_info_header();

void main(){
	
	stud st;
	
	printf("\nEnter student name: ");
	gets(st.name);
	
	printf("\nEnter student stream: ");
	gets(st.stream);
	
	printf("\nEnter student id: ");
	scanf("%d", &st.id);
	
	printf("\nEnter student class: ");
	scanf("%d", &st.std);
	
	printf("\nEnter student age: ");
	scanf("%d", &st.age);
	
	
	
	printf("Name:\t %s\n", st.name);
	printf("Stream:\t%s\n", st.stream);
	printf("ID:\t%d\n", st.id);
	printf("Std:\t%d\n", st.std);
	printf("Age:\t%d\n", st.age);
	
	write_student_info_header();
}

void write_student_info_header(){
	
	FILE *file;
	
	file = fopen("student_info.csv", "w");
	
	fprintf(file, "Name,Stream,ID,Std,Age");
	
	fclose(file);
}

void write_student_info(stud st){
	
	
	
	
}
