/*
    Peak Element: An element is called a peak element if its value is not smaller than the value of 
    its adjacent elements(if they exists). Given an array arr[] of size N, find the index of any one of its peak elements.

    Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 

    Example 1:
    N = 3
    arr[] = {1,2,3}
    Output: 2
    Explanation: index 2 is 3.
    It is the peak element as it is 
    greater than its neighbour 2.

    Example 2:
    N = 2
    arr[] = {3,4}
    Output: 1
    Explanation: 4 (at index 1) is the 
    peak element as it is greater than 
    its only neighbour element 3.
*/

#include<stdio.h>

void PrintArray(int arr[], int n){

    // This Metod will used to print the array

    int i;

    printf("\nArray: [");
    for(i=0; i<n; i++){
        
        if(i==n-1)
            printf("%d",arr[i]);
        else
            printf("%d,",arr[i]);
    }
    printf("]\n");
}

int PeakElement(int arr[], int n){

    // This function will be used to find out the peak element in an array and it will return the peak element index..

    // finding peak element or its index is same as finding the max element in the array.
    int i;
    int peak=0; // peak is the index of the peak element, initially we are considering that 0th element is the peak element.

    for(i=0; i<n; i++){

        if(arr[i]> arr[peak])
            peak = i;
    }

    return peak;
}

void main(){

    int arr[] = {1,2,4,6,5};
    int peak;
    peak = PeakElement(arr, 6);

    printf("\nPeak element at %d is %d. \n", peak, arr[peak]);


}