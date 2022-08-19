#include<stdio.h>
#include<string.h>

// struct keyword;
// struct <struct_name>{};
// strcpy();

//a new user defined data type.
struct Student{
	char name[16];
	int age;
	char graduation[7]; 
};



// syntax for new data type
// struct Student <variable-name>

// struct Student st1 = {"Manish", 26, "b.tech"}


void struct_init();
void print_st(struct Student);
void get_students();

void main(){
	
	struct Student st1;  // here 'struct Student' is a new user-defined data type and st1 it's variable.
	// st1 will hold the memory block after creation of it.
	// struct Student structure will not have any memory.
	
	// . operator/ member operator.
	// -> reference operator.

	
//	strcpy(st1.name, "Manish");
//	strcpy(st1.graduation, "b.tech");
//	st1.age = 26;
//	
//	printf("Name:\t\t%s\n", st1.name);
//	printf("Graduation:\t%s\n", st1.graduation);
//	printf("Age:\t\t%d\n", st1.age);
//	


//	struct_init();

	get_students();
	
}

// int age[4];

// struct Student std[4];


void struct_init(){
// in this function we will initialize the structure and print it.	

	struct Student st1 = { "Manish", 26, "b.tech"};
	
	struct Student st2 = {"Abhishek", 18, "BCA"};
	
	print_st(st1);
	print_st(st2);
	
}


void print_st(struct Student st){
	
	printf("Name:\t\t%s\n", st.name);
	printf("Graduation:\t%s\n", st.graduation);
	printf("Age:\t\t%d\n", st.age);
	printf("\n---------------------------\n"); // for next student 
}


// storing multiple students.

void get_students(){
//	Now we will make array of our new data type (struct Student)

	struct Student st[2];
	char flush[2];
	int i =0;
	
	int st_size = 2;
	
	for(i=0; i<st_size; i++){
		
		printf("Enter Student %d Name: ", i+1);
		gets(st[i].name); 		
		printf("Enter Student %d graduation: ", i+1);
		gets(st[i].graduation);
		
		printf("Enter Student %d Age: ", i+1);
		scanf("%d", &st[i].age);
		
		// in need to flush current data stream.
		gets(flush);  // a dummy gets to flush the input of age.
		printf("\n------------------------------------------\n\n");
	}
	
	
	for(i=0; i<st_size; i++){
		print_st(st[i]);
	}
}


