#include<stdio.h>

/*
	In this section we will see that how memory is allocated to an arrary
	and how each element is associted to a memory block in array.
*/

void printArray(int[], int);
// declaring the printArray function to print the array
// since our function will take an array as argument, hence we are declaring
// our parameter as int[] array of integer typ,

void main(){
	
	// fir
	
	int arr[6] = {10,20,30,40,50,60};
	// {10,20,30,40,50,60} this is initializer list for our array.
	// array will automatically pick the value associated with index number.
	// 0 --> 10, 5 --> 60
	
	printf("Array: ");
	printArray(arr, 6);
	
	printf("\n");
	printf("Size of int data type: %d\n", sizeof(int));
	
	// Now we will test our inital memory address.
	printf("Intial memory address of array: %d\n", arr);
	printf("Array's last values memory addres: %d\n", &arr[5]);
}

void printArray(int arr[], int n){
	
	int i=0;
	for(i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}


