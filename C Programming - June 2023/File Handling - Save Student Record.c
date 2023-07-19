#include<stdio.h>
#include<string.h>


typedef struct Student {
	char name[30];
	int age;
	float height;
	int rollno;
} st;

st getStudent();
void displayStudent(st student);

int main() {

	FILE* file = NULL;
	char str[100] = { '\0' };

	errno_t err = fopen_s(&file, "testfile.txt", "w");

	if (!err) {
		printf("Enter Student Data: \n");
		printf("===============================\n");

		st student = getStudent();

		printf("Writing Student Data to file.\n");
		displayStudent(student);
		printf("================================\n");

		fprintf_s(file, "%s,%d,%f,%d", 
			student.name, student.age, student.height, student.rollno);

		printf("\n Student Data has been successfully saved..!");
		fclose(file);
	}
	else {
		perror("fopen failed: ");
	}

	return 0;
}

st getStudent() {
	
	st student; // 
	char ch = '\0';

	printf("Enter Student Name: ");
	gets_s(student.name, 30);

	printf("Enter Student Age: ");
	scanf_s("%d", &student.age);

	printf("Enter Student Height: ");
	scanf_s("%f", &student.height);

	printf("Enter Student Roll No: ");
	scanf_s("%d", &student.rollno);

	return student;

}

void displayStudent(st student) {
	printf("Name: %s\n", student.name);
	printf("Age: %d\n", student.age);
	printf("Height: %f\n", student.height);
	printf("Roll No: %d\n", student.rollno);
}