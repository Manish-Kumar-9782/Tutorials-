#include<stdio.h>
#include<string.h>

/*
*  1. function name: print_array
*  2. function will not return any thing
*  3. it will take an array and length of the array.
* 
*  declare the function.
* 
*	pass by value, pass by reference
* 
*	reference operator &
*	&arr
	data-type arr[] --> arr will contain address of its 0th element.
*/

void print_array(int[], int);
void input_array(int[], int);

void main() {
	int arr[6] = { 0 };
	printf("Enter array value of lenght 6: ");
	input_array(arr, 6);
	print_array(arr, 6);

	getch();
}

void print_array(int arr[], int length) {
	int i;
	printf("Array: [");
	for (i = 0; i < length; i++) {
		
		// we will provide comma and space if our array index in not last element
		if (i < length - 1) {
			printf("%d, ", arr[i]);
		}
		else {
			printf("%d", arr[i]);
		}
	}
	printf("]");
}

// in this function we will pass our array by reference.
void input_array(int arr[], int length) {

	int i;
	for (i = 0; i < length; i++) {
		scanf("%d", &arr[i]);
	}

}
