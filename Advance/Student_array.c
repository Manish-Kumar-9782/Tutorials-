#include<stdio.h>
#include<string.h>


typedef struct Student{		char name[16];	int age;	char graduation[8];
}stu;


void print_stu(stu);
// here stu is a new data type.

// we are going to make array of our new data type (stu).

void main(){
//	int var[]

	stu students[2];
	
	int st_size = 2;
	int i=0;
	
	char flush[2]; // to flush/empty the stream .
	
	for(i=0; i<st_size; i++){
		
		printf("Enter Student %d name: ", i+1);
		gets(students[i].name);
		
		printf("Enter Student %d Graduation: ",i+1);
		gets(students[i].graduation);
		
		printf("Enter Student %d Age: ",i+1);
		scanf("%d",&students[i].age);
		
		gets(flush);
		
		printf("\n----------------------------------\n\n");
	}
	
	for(i=0; i<st_size; i++){
		print_stu(students[i]);
	}
	
}


void print_stu(stu st){
	
	printf("Name:\t\t%s\n",st.name);
	printf("Graduation:\t%s\n",st.graduation);
	printf("Age:\t\t%d", st.age);
	printf("\n\n");
}
