#include<stdio.h>

void main(){
	
	enum WeekDay {Sunday=0, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; // these are the values of WeekDay enum data.
	// first we have declared the Weekday as a enumerated data type.
	enum WeekDay week_start, week_end;  // making WeekDay variables which have access to WeekDay values.
	int today;
	
	//week_start = Sunday;
	week_end = Saturday;
	
	
	// getting today value form the user input.
	printf("Enter the today value.");
	scanf("%d",&today);
	
	
	if(Sunday== today){
		printf("\nToday is Sunday.");
	}
	else if(today>week_end){
		// here week end value will be 6.
		printf("\n Inputted value is not a day.");
	}
	else{
		printf("\nToday is not Sunday");
	}
	
	
	
	
}
