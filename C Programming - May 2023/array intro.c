#include<stdio.h>

// Array: it is a container or an data structure in which we store similar kind of 
// data type values, in consecutive order.
// each item of array assigned with index number, which defines the position of the
// item inside that array.
// index: index number in array always start from 0.
// length: it is the length of array which defines how many element block we have
// for that array.

/*
	syntax:
		<data-type> var_name|array_name[length]; // declare the array
*/

void main() {
	// now we will store 4 value of integer in an array.
	int numbers[4]; // declare the array.
	printf("array - number item 3: %d\n", numbers[2]);

	// initialize array as empty or zero values
	int zero_array[4] = { 0 };// 
	printf("array - zero_array item 3: %d\n", zero_array[2]);

	// initialize each value with initializer list
	int _array[4] = { 10, 20, 30, 40};// 
	printf("array - _array item 1: %d\n", _array[0]);
	printf("array - _array item 2: %d\n", _array[1]);
	printf("array - _array item 3: %d\n", _array[2]);
	printf("array - _array item 4: %d\n", _array[3]);

	printf("\n\n=================================\n");
	for (int i = 0; i < 4; i++) {
		printf("array - _array item 1: %d\n", _array[i]);
	}
	printf("\n=================================\n\n");

}