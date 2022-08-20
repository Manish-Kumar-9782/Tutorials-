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


// Syntax To make variable: struct <strcut-name> <var-name>;


void main(){
	
	struct Student st;
	
	strcpy(st.name, "Manish");
	strcpy(st.graduation, "b.tech");
	st.age = 26;
	
	printf("Name:\t\t%s\n",st.name);
	printf("Graduation:\t%s\n",st.graduation);
	printf("Age:\t\t%d", st.age);
	
}
