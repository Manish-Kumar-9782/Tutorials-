/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.
Expected Time Complexity: O(N)
Expected Oxilary space: O(1)
*/

// In this section we will check the a number is missing or not in a given range of integer from 1 to N.

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

int MissingNumber(int arr[], int n){
    
    // This method will be used to check that a number is missing form an array which is having a integer number in range 1 to N;

    // Solution method: In this method first of all we will get the sum of first 1 to N integers.
    // after getting the sum we will subtract each number from sum, in the we will get the missing number
    // This total subtraction should be zero so that why the remaining number will be the missing number.

    int i;
    int Missing=0;
    // To find the missing number we will first calculate the sum of the array element.

    // 1. first we will calculate the sum of n integers.
    for(i=1; i<=n; i++){

        Missing += i;
    }

    // 2. Now we will decrease the sum by arr[i] value.
    for(i=0; i<n; i++){

        Missing -= arr[i];
    }
    return Missing;
}

void main(){

    int arr[] = {6,1,2,8,3,4,7,10,5};
    int n=10;
    int Missing;
    //n = sizeof(arr)/sizeof(arr[0]);

    printf("\nArray size: %d\n", n);
    PrintArray(arr,n);

    Missing = MissingNumber(arr,n);
    
    printf("\nMissing Number: %d\n", Missing);
}