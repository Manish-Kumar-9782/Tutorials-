#include<stdio.h>
#include<string.h>
// structure: keyword struct

/*
	struct <data-type-name>{
		int year;
		int month;
		int day;
	}
*/

struct Student {
	char name[20]; // array
	int age;
	float height;
	char bloodGroup[4];
};




void main() {
	struct Student st;
	strcpy(st.name, "Kuldeep");
	// Note assigning the string to name of student.
	st.age = 20;
	st.height = 5.5;

	printf("Student name: %s\n", st.name);
	printf("Student age: %d\n", st.age);
	printf("Student height: %f\n", st.height);
}
