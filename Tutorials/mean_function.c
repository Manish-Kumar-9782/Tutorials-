// in this section we will see how to pass an array in a function.
// Example compute the mean of these two list of int data types.

// 12,15,42,56,23,78,56,96,56
// 12 , 45, 32 ,56 ,95 ,87 ,45, 21, 32, 58, 41, 14, 25, 52, 63, 74, 58
#include<stdio.h>

//declaration of the function 
float mean(int [], int);  // formal parameters


int main(){
	// calling function
	
	int list1[] = {12,15,42,56,23,78,56,96,56};
	int list2[] = {12 , 45, 32 ,56 ,95 ,87 ,45, 21, 32, 58, 41, 14, 25, 52, 63, 74, 58};
	float result=0;
	int arr_size = 0;
	
	// getting the size of the list1 array.
	arr_size = sizeof(list1)/sizeof(list1[0]);
	result = mean(list1, arr_size);  // first call
	
	printf("Mean of list1: %.2f", result);
	
	// getting the size of the list2 array.
	arr_size = sizeof(list2)/sizeof(list2[0]);
	result = mean(list2, arr_size); // second call 
	
	printf("\nMean of list2: %.2f", result);	
	
}


// definition of the function.
float mean(int arr[], int n) // actual parameter.
{
	float result =0;
	int i=0;
	
	for(i=0; i<n; i++){
		
		result += arr[i]; // adding all the elements.
	}
	
	// computing the mean of the elements.
	result = result/n;
	
	return result;
	
}
