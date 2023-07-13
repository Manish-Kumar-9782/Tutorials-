#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum BloodGroup { A_POSITIVE = 101, A_NEGATIVE, 
	B_POSITIVE, B_NEGATIVE, AB_POSITIVE, 
	AB_NEGATIVE, O_POSITIVE, O_NEGATIVE };

 struct Student {
	char name[30];
	char std[5];
	char subject[30];
	int age;
	float height;
	enum BloodGroup bloodGroup;
};

 typedef struct Student St; 
 typedef enum BloodGroup Bg;
 // making a short nike name oft struct Student

 St* createStudent(const char*, const char*, const char*, int, float, Bg);
 const char* get_bloodGroup(Bg);
 void showStudent(St*);

 void main() {
	 St* st1 = createStudent("Kuldeep", "11th", "Arts",
		 18, 5.3, B_POSITIVE);

	 showStudent(st1);
 }


 St* createStudent(const char* name, const char* std, 
	 const char* subject, int age, float height, Bg bloodgroup) {

	 St* student = (St*)malloc(sizeof(St));

	 // assign name
	 strcpy_s(student->name, 30, name);

	 // assign std
	 strcpy_s(student->std, 5, std);

	 // assign subject
	 strcpy_s(student->subject, 30, subject);

	 student->age = age;
	 student->height = height;
	 student->bloodGroup = bloodgroup;

	 return student;
 }

 void showStudent(St* st) {
	 printf("Name: %s\n", st->name);
	 printf("Class: %s\n", st->std);
	 printf("Subject: %s\n", st->subject);
	 printf("Age: %d\n", st->age);
	 printf("Height: %f\n", st->height);
	 printf("BloodGroup: %s\n", get_bloodGroup(st->bloodGroup));
 }

 const char* get_bloodGroup(Bg bg) {

	 switch (bg)
	 {
	 case A_POSITIVE: return "A+";
	 case A_NEGATIVE: return "A-";
	 case B_POSITIVE:return "B+";
	 case B_NEGATIVE:return "B-";
	 case AB_POSITIVE:return "AB+";
	 case AB_NEGATIVE:return "AB-";
	 case O_POSITIVE:return "O+";
	 case O_NEGATIVE:return "O-";
	 default: return "";
	 }
 }