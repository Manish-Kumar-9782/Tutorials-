// Program: Frequency counting in better way.

/*Input data:
43 65 51 27 79 11 56 61 82 09 25 36 07 49 55 63 74
81 49 37 40 49 16 75 87 91 33 24 58 78 65 56 76 67
45 54 36 63 12 21 73 49 51 19 39 49 68 93 85 59
*/


#include<stdio.h>

#define MAXVAL 50
#define COUNTER 11

void main(){
	float value[MAXVAL];
	int i, low, high;
	int group[COUNTER] = {0,0,0,0,0,0,0,0,0,0,0};
	// we have initialized the group values at the compile time this will help us in furthur computation.
	
	// Reading and counting the values:
	
	for(i=0; i<MAXVAL; i++){
		
		// 	Reading all the values.
		scanf("%f", &value[i]);
		
		// Now we need to count the values.
		++group[(int)(value[i]/10)];  // we will increase the group number by one. intialy it is zero.
		
		// expalnation of above code
		/*	(int) is the type casting means it will convert our float value in integer value.
			value(i)/10  we are dividing the value[i] by 10 this will give the number of the group it means
			
			if 59/10 will give us 5.9 and the integer value is 5 it means this group is belongs to the group number 5.
			by this method we will get all the groups frequency in faster way.
		*/
	}
	
	// Now we need to print a frequency table.
	
	
	printf("\n--------------GROUP FREQUENCIES--------------\n");
	printf("\nGroup	Range	Frequency\n");
	
	for(i=0; i<COUNTER; i++){
		
		low = i*10;
		
		if(i==10)
			high=100;
		else
		high = low+9;
		
		printf(" %2d  %3d to %3d  %3d\n", i+1, low, high, group[i]);
	}
	
}
