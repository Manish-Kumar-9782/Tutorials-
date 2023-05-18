#include<stdio.h>

/*
	In this section we will learn how to make array of structure user defined
	data types.
	
	to create the array of structure data type we have the same following syntax:
	
	synta:
		struct name arr[len];
*/

// Now we will create a new structure data type for student
struct Student{
	
	char name[20];
	int age;
	float height;
	char bloodGroup[4];
};

// declaring a function to set the data of students.
void setStudents(struct Student[], int);
void showStudents(struct Student[], int);

void main(){
	
	// Now we will create an array for our Student data type structure.
	
	struct Student sts[1];

	setStudents(sts, 1);
	showStudents(sts,1);
	
	
}


void setStudents(struct Student sts[], int len){
	
	int i=0;
	
	for(i=0; i<len; i++){
		printf("Enter Student Name: " );
		gets(sts[i].name);
		
		printf("Enter Student BloodGroup: " );
		gets(sts[i].bloodGroup);
		
		printf("Enter Student age: " );
		scanf("%d",&sts[i].age);
		
		printf("Enter Student height: " );
		scanf("%f",&sts[i].height);
		
		scanf("%c"); // to flush the remaing charater inside our stream.
		printf("\n-----------------------------------\n");
		
	}
	
//	showStudents(sts,len);
}

void showStudents(struct Student sts[], int len){
		int i=0;
		
	for(i=0; i<len; i++){
		printf("\nEnter Student Name: %s", sts[i].name);
		
		printf("\nEnter Student BloodGroup: %s", sts[i].bloodGroup);
		
		printf("\nEnter Student age: %d", sts[i].age);
		
		printf("\nEnter Student height: %f", sts[i].height);
				
		printf("\n-----------------------------------\n");
	}
}

