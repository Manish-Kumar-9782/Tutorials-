#include<stdio.h>

/*
	In this section we will see the structures in c.
	
	keyword struct, is used to create a new user-defined data type, in this we can 
	store multiple type of data by using the different kind of type inside that 
	structure.
	
	strcut name{
		char name[][];
		int value1;
		char value2;
		float value3;
	}
	
	// Now we create a new varable of our new data type.
	// all variable inside are called as data memebers of that 
	// structure in taht they are definied.
		
	struct name myname = {}
	
	Assing Data memebers:
		myname.memberName
*/

// defining a Student type structure as new data-type.
struct Student{
	
	char name[20];
	int age;
	float height;
	char bloodGroup[4];
};


void main(){
	
	// creating a new student using our new data-type --> struct Student.
	struct Student st2;
	// if we want to assign values during creating the variable we can 
	// use initializer list.
	struct Student st = {
		"manish", 27, 5.6, "O-"
	};
	
	
	// assing the structur data memeber.
	printf("Student Name: %s\n", st.name);
	printf("Student Age: %d\n", st.age);
	printf("Student Height: %0.1f\n", st.height);
	printf("Student BloodGroup: %s\n", st.bloodGroup);
	
}
