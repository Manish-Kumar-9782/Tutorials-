#include<stdio.h>
#include<stdlib.h>


int* newIntArray(int size);

void main() {

	// a pointer array
	int arr_size = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &arr_size);

	//int* arr = (int*)malloc(sizeof(int) * arr_size);
	int* arr = newIntArray(arr_size);

	for (int i = 0; i < arr_size; i++) {
		printf("Enter the index %d value: ", i);
		scanf_s("%d", &arr[i]);
	}

	// Now displaying our array:

	printf("array: ");
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}

}

// returning an array from a function
int* newIntArray(int size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	return arr;
}