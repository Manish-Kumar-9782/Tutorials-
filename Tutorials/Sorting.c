
// in This section we will make a sorting program which will sort a integer value.
// we will store all the value in an array so in another word we will sort the array.
// To sort an array we will use pointers.
#include<stdio.h>

int swap(int*, int*);
// first of all we need to make a function which will swap the value which is required to change their postion for sorting.

int sort(int [], int size);
// This function will be used to sort the array

void printarr(int [], int);
// d

int main(){
	
	int arr[5] = {45, 28, 83, 35,55};
	
	printf("Original Array: ");
	printarr(arr, 5);
	
	sort(arr, 5);
	
	printf("Sorted Array: ");
	printarr(arr, 5);
	
	
}


int swap(int *a, int *b){
	// now in this function we will first make a temp varaible in which we will hold the value of a.
	// and after that we will make a = b;
	// and finally we wil make b= temp.
	
	int temp = *a; // since a is a pointer variable so to get the value of address which hold by the pointer a we need to use indirection operatior.(astrik)
	*a = *b;
	*b = temp;
}

int sort(int arr[], int size){
	
	// Now in this we need to check that a value is less than or not 
	
	int i,j;
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++){
			
			if(arr[i]<arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
	
}

void printarr(int arr[], int size){
	
	int i;
	for(i=0; i<size; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
	
}

