#include<stdio.h>

/*
	2D array:
		
		[
			[1,2,4], 
			[4,5,6], 
			[7,8,9]
		]

		[1,2,3,4,5,6,7,8,9]

		9*data-type-size == x-bytes

	Note: all inner array must have same size.

	size of outer array will be depend on the number of inner arrays.

	total size/ memory size: outer array element * inner array size

	int array[3][3] = {
			{1,2,4}, 
			{4,5,6}, 
			{7,8,9}
		}

		{ {1,2,3}, {4,5,6}, {7,8,9} };
*/


void printArray2(int[], int);

void main() {

	// 2d array for integer
	 double array[3][3] = {
			{1,2,3}, // row 0
			{4,5,6}, // row 1
			{7,8,9} // row 2
	};

	// 2d array for characters
	char names[5][50] = {"Kuldeep", "Bhanu", "Karan", "Kurshid", "Sushma"};
	// in 2d character array we can store 


	printArray2(array, 9);

	printArray2(array[0], 3);
	printArray2(array[1], 3);
	printArray2(array[2], 3);

	// array[0][1] ==> 2

	// array[3][2] ==> garbage_value;
	// array[2][2]  ==> 9;

	for (int i = 0; i < 5; i++) {
		printf("%d: %s\n", i, names[i]);
	}

	printf("\n----------------------------------------\n");
	printf("size of array: %d\n", sizeof(array));
	printf("size of names: %d\n", sizeof(names));
}


void printArray2(int arr[], int n) {

	printf("array: [");
	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			printf("%d,", arr[i]);
		}
		else {
			printf("%d", arr[i]);
		}
	}
	printf("]\n");
}