#include<stdio.h>

// A basic introduction to pointer.
// Pointers are used to store memory address of other variables.

void main(){
	
	int arr[10] = {1,2,3,4,5,6,7,8,9};
	int pr[10] = {10,11,12,13,14,15,16,17,18,19};
	
	int i=0;
	
	for(i=0; i<20; i++){
		printf("\naddress of arr %d - %d", i, &arr[i]);
	}
	printf("\n\n");
	for(i=0; i<20; i++){
		printf("\naddress of pr %d - %d", i, &pr[i]);
	}
	
	printf("\n\n");
	
	for(i=0; i<20; i++){
		printf("\nvalue at pr %d - %d", i, pr[i]);
	}
	
}
