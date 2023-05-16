#include<stdio.h>
#include<string.h>
#include<conio.h>


/*
	1. declare our function with its appropriate return type
	2. function name: student_info
	3. make variable of struct Student
	4. take user input for each data memeber for Student
	5. return Student variable.
	
	return-type functionname(parameterList);
	
*/

//void struct_Student  // bhavaya
//struct Studnet_info(int age); // kuldeep 2
//struct Studnet_info(float height); // kuldeep 2
//
//void student_info(int age, float height); // kursheed
//
//
//void structStudent_info(int age);   // karan singh
//void struct Student_info(float height); // karan singh
//
//void Student_info(int); // sushma
//void main (){
//	struct Student st;
//} // kuldeep

struct Student {
	char name[20]; // array
	int age;
	float height;
	char bloodGroup[4];
};


struct Student student_info();

void display_student(struct Student st){
	printf("Name: %s\n", st.name);
	printf("Age: %d\n", st.age);
	printf("Height: %f\n",st.height);
	printf("BloodGroup: %s\n",st.bloodGroup);	
}
// ==================================== //
void main(){
	
	struct Student st = student_info();
	
	printf("\n========================================\n");
	display_student(st);
	getch();
}
// ==================================== //

struct Student student_info(){
	struct Student st;
	
	printf("Enter Student name: ");
	gets(st.name);  // getting name from user and assigning the value to st.name
	
	printf("Enter Student BloodGroup: ");
	gets(st.bloodGroup);
	
	printf("Enter Student Age: ");
	scanf("%d", &st.age);
	
	printf("Enter Student Height: ");
	scanf("%f", &st.height);
	
	return st;
}
