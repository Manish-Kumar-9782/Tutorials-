// Program: Calculate the total number to pass in a class.

#include<stdio.h>

#define MAX_SUB	 5  // this is used to restrict the maximum number of subject in a class.
#define PASSING_MARKS 180
#define SMARKS 36  // minimum subject marks to pass in per subject.

void main(){
	
	int  total_number=0, subject_number=0;
	int i, s_count=0;
	// total_number: this will hold the sum of all the subject number.
	// subject_number: this we be used to hold the inputted value of per subject number.
	// s_count: it will track total number of suplimentry subjects.
	enum Subjects {Biology=0, Physics, Chemistry, English, Hindi};
	
	for(i=1; i<=5; i++){
		
		printf("Enter the number of subject %d:  ", i);
		scanf("%d", &subject_number);
		
		// Now we need to sum the total_number with new subject_number.
		total_number += subject_number;
		
		// checking the subject number that a student got suplimentry or not.
		
		if(subject_number < SMARKS){
			// if this conidition is satisfied then we need to count a suplimentry subject by one.
			s_count++;
			printf("Suplimentry in Subject :%d \n\n", i);
		}
		
	}
	
	// checking that student is passed or failed.
	
	if(total_number >=  PASSING_MARKS){
		
		if (s_count>=3){
			printf("\nYou have got suplimentry in 3 or more subjects\n Result: Failed");
		}
		else{
			printf("\nYou have suplimentry in 1 or 2 subjects\n Result: Passed");
		}
		
	}
	else{
		printf("\nFailed\n");
	}
	printf("\n\ntotal Number: %d", total_number);
	
}
