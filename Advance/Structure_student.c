#include<stdio.h>
#include<string.h>

// strcmp(), strcpy(), strlen();

// structure is a user-defined data type
// we can make our own data types by using structure.

// keyword struct

/*
	defination body of struct
	
	struct <data-type-name>{
		
		data-type1 <varname>;
		data-type2 <varname>;
		data-type3 <varname>;
		data-type4 <varname>;
	};
*/

struct Student{
	
	char name[16];
	int age;
	char graduation[8];
};


// nicknmae/alias name
// typedef 

typedef struct StudenT{
	
	char name[16];
	int age;
	char graduation[8];

}stu;


// Syntax To make variable: struct <strcut-name> <var-name>;

void print_st(struct Student);
// here struct Student is a new user-defined data type
void print_stu(stu);
void main(){
	
	struct Student st;
	
	// making another student by using typedef version of student.
	stu st1;
	
//	strcpy(st.name, "Manish");
//	strcpy(st.graduation, "b.tech");
//	st.age = 26;
	
	strcpy(st1.name, "Manish");
	strcpy(st1.graduation, "b.tech");
	st1.age = 26;


	print_stu(st1);	
	
}


// to print student information on the console/screen
void print_st(struct Student st){
	
	printf("Name:\t\t%s\n",st.name);
	printf("Graduation:\t%s\n",st.graduation);
	printf("Age:\t\t%d", st.age);
}

void print_stu(stu st){
	
	printf("Name:\t\t%s\n",st.name);
	printf("Graduation:\t%s\n",st.graduation);
	printf("Age:\t\t%d", st.age);
}
