// Program: Frequency counter of the number of values in b/w a group.

/*43 65 51 27 79 11 56 61 82 09 25 36 07 49 55 63 74
81 49 37 40 49 16 75 87 91 33 24 58 78 65 56 76 67
45 54 36 63 12 21 73 49 51 19 39 49 68 93 85 59*/


// Write a program to count the number of students belonging to each of
// following groups of marks 0-9,10-19, 20-29,.....100.

// in this we will have total 11 groups we need an array of size 11.
// and also we need an array of 50 elements since inputted values will be 50.


#include<stdio.h>

void main(){
	
	int values[50], freq[11], input_value, i, j, freq_count=0;
	int st=0, end=9, total_value=0;
	// values: values array will hold all the inputted values.
	// freq: array will be used to hold the absolute frequency values of the groups.
	
	// asking the user to input the values.
	
	printf("Enter the all 50 values: ");
	for (i=0; i<=49; i++){
		
		scanf("%d", &input_value);
		values[i] = input_value;
		
	}
		
	// now we need to run a loop for each group
	
	printf("Gorup No\tGroup Range\tFrequency\n");
	printf("-------------------------------------------\n");
	
	for(i=0; i<=10; i++, st+=10, end+=10){
		// this outer loop will control the group position in the array.
		
		for(j=0; j<=49; j++){
			// this inner loop will search for the value which belongs to the particluar group.
			if(values[j]>=st && values[j]<=end){
				freq_count++;
			}
		}
		freq[i] = freq_count;
		freq_count = 0;
		
		printf("%d\t\t%d-%d\t\t%d\n", i+1,st,end,freq[i]);
	}
	
/*	printf("\nFreq count: ");
	
	for(i=0; i<=10; i++)
		{
			printf("%d, ", freq[i]);
			total_value+= freq[i];
		}
		
	printf("\nTotal counted values: %d", total_value);
			
*/	
}
