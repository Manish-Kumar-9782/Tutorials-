#include<stdio.h>
#include<string.h>

/*
	array: container or data structure which can hold multiple value of similar types.
	all values are store in consecutive order

	array length: it tells that how many values we can store in single array.
	data type: it tells to memory allocator that how much memory bytes are required to
	create each block for each value.

	index: array index always starts from zero 0.


*/



void main() {
	
	int arr[5]; 
	// declared an array of int type having only 6 element.
	// data type int (4-byte)
	// if there no initialization of array , all block will have random values.


	// assigning values to array

	arr[0] = 444;
	arr[1] = 45;
	arr[2] = 475;
	arr[3] = 450;
	arr[4] = 48;

	// to display an array we need three things
	// 1. array itself.
	// 2. length of the array (size)
	// 3. for loop to iterate over the array element

	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	
	

	// if we want to remove garbage values then we should initialize array with 0;
	
}