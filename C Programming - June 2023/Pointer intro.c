#include<stdio.h>
#include<stdlib.h>

/*
	to create pointer

	<data-type> *variable name;  --> declaration
	<data-type> *variable name = value; --> initialization 
*/

void printArray2(int arr[], int n);

int* newIntArray(size) {
	int* ptr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
	return ptr;
}

void main() {

	int a = 101;

	int* ptr = &a;


	printf("value of var a: %d\n", a);
	printf("size of p: %d\n", (int)sizeof ptr);
	printf("\naddress of a: %p\n", &a);
	printf("address of p: %p\n", &ptr);
	printf("Value of p: %p\n", ptr);
	printf("Value of a from ptr: %d\n", *ptr);

	*ptr = 200;
	printf("After changing Value of a from ptr: %d\n", *ptr);
	printf("value of var a: %d\n", a);

	int array_size = 6;

	int* number = newIntArray(array_size);

	printArray2(number, array_size);

}

void printArray2(int arr[], int n) {

	printf("array: [");
	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			printf("%d,", arr[i]);
		}
		else {
			printf("%d ", arr[i]);
		}
	}
	printf("]\n");
}