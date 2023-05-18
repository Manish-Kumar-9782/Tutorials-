#include<stdio.h>

/*
	In this section we will discuss on array in c.
	
	Array: array is data structrue, which holds the similar type of data (multiple values)
	, in consecutive order. array is a sequential data structure, it means we can perform 
	the repetitive task. 
	
	In array each element/value will be placed at a given index number,which is starts 
	from 0 to n, increasing order in sequence.
	
	indexing starts from zero (0).
	
	syntax: 
	<data_type> <name>[length]; 
		length it is the length of array. length of array defines 
	that how many values we need to store in an array.
	
	Accessing: 
		<data_type> variable = array[index];
		// now we have the array value from index number 
		
	Assingment:
		array[index] = value; 
		// Note: value must match the data type of array values.
*/

void main(){
	
	int arr[5];
	char name[10] = 
	// our array length is 5.
	
	int newArray[5] = {0};
	// intializing the all newArray element with zero.
	
	// assigning the values in array.
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;
	
	
	printf("array value at index 0: %d\n", arr[0]);
	printf("Value form newArray at index 4: %d\n", newArray[4]);
	
	int i=0;
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	
	// array : [1,2,3,3...., n]
}
