#include<stdio.h>

// In this section we will make a student info program by using 2D array.

void student_info();

void main(){
	
	student_info();
	
}

void student_info(){
//	students info data arrys
	char names[4][16] = {'\0'};
	int Age[4] = {0};
	char graduation[4][8] = {'\0'};
	
	char flush[2];
	
	int i=0;
	int st_size = 2;
	
	for(i=0; i<st_size; i++){
		
		printf("Enter Student %d Name: ", i+1);
		gets(names[i]);
		
		printf("Enter Student %d graduation: ", i+1);
		gets(graduation[i]);
		
		printf("Enter Student %d Age: ", i+1);
		scanf("%d", &Age[i]);
		
		// in need to flush current data stream.
		gets(flush);  // a dummy gets to flush the input of age.
		printf("\n------------------------------------------\n\n");
	}
	
	// Header string formatting.
	printf("%-16s %-5s %-10s ", "Name", "Age" , "graduation");
	printf("\n---------------------------------------------\n");
	
	for(i=0; i<st_size; i++){
		printf("%-16s %-5d %-10s\n", names[i], Age[i], graduation[i]);
	}
	
	
}


