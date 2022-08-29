#include<stdio.h>

// A basic introduction to pointer.
// Pointers are used to store memory address of other variables.

void main(){
	
	FILE *fp;
	
	int a = 10;
	int arr[10];
	printf("value of a: %d \n", a);
	printf("address of a:%p\n", &a);

	int *ptr; // a pointer of named by 'ptr' (in other word ptr is the name of the pointer variable.)
	// here 'int' define that which kind of value is taken by the variable pointer point.
	
	ptr = &a; // passing address of variable a to 'ptr' pointer variable
	
	printf("addres of a in ptr: %d\n", ptr);
	printf("addres of a in ptr: %p\n", ptr);
	
	printf("address of ptr: %p", &ptr);
	printf("\nvalue of a through ptr: %d", *ptr);
	printf("\naddress of arr: %p", arr);
	
	printf("\narr 15th value: %d", arr[15]);
}
