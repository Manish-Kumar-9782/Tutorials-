// in this section we will make a program to check that a student is passed or not
// we will also check about the suplimentry in any subject 

// we will make two function to do this job  total_number and fail_pass function.

#include<stdio.h>
#define MAX_SUB	 5  // this is used to restrict the maximum number of subject in a class.
#define PASSING_MARKS 180
#define SMARKS 36  // minimum subject marks to pass in per subject.

int sum(int [], int);
void failpass(int, int);
int sup(int [], int);

void main(){
	
	enum Subjects {Biology=0, Physics, Chemistry, English, Hindi};
	int Numbers[5];
	int i;
	int total = 0, ssub=0;
	// ssub: ssub is used to show suplimentry subject
	printf("Enter your numbers: ");
	for(i=0; i<5; i++)
		scanf("%d", &Numbers[i]);
	
	ssub = sup(Numbers, 5);  // counting suplimentries
	total = sum(Numbers, 5); // this sum function will add all the Numbers 
	
	// now we will check that a student is passed or not.
	
	failpass(total, ssub);
	
}

int sum(int arr[], int size){
	// this function will add all the numeric values given in an array or a list.
	
	int total=0;
	int i;
	for(i=0; i<size; i++){
		total += arr[i];
	}
	
	return total;
}

void failpass(int number, int suplimentries){
	// This function will check that a student is passed or not.
	printf("Total obtained marks: %d", number);
	
	
	if(number >= PASSING_MARKS){
		
		if(suplimentries >=3){
			printf("\nYou have suplimentries in %d subjects. \n", suplimentries);
			printf("\nFAILED...");
		}
			
		else
			printf("\nPASSED");
	}
	else
		printf("\nFAILED...");
	
}


int sup(int arr[], int size){
	
	int count =0;
	int i;
	for(i=0; i<size; i++){
		
		if(arr[i] < SMARKS)
			count++;
	}
	
	return count;	
}



