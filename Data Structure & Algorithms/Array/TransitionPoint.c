
/*
    Transition Point: Given a sorted array containing only 0s and 1s, find the transition point. 

    * Transition point is the point where we will find out first appearence of the 1.

    Example 1:

        Input:
        N = 5
        arr[] = {0,0,0,1,1}
        Output: 3
        Explanation: index 3 is the transition 
        point where 1 begins.

    Example 2:

        Input:
        N = 4
        arr[] = {0,0,0,0}
        Output: -1
        Explanation: Since, there is no "1",
        the answer is -1.
*/

#include<stdio.h>

int TransitionPoint(int arr[], int n){

    // Since TransitionPoint is the point where we get the first appearence of the 1.
    // So we need to make a condition we get the first 1 in the array.

    
    int i;

    for(i=0; i<n; i++){

        if(arr[i] != 0)
            return i; // if ith value does not 0 it means it will be 1 so we will return the index at which we found 1.
            // if we found the first appearence of 1 then we will return its index position.
    }
    // if we dont found any appearance of 1 then we will return -1.
    return -1;
}

void main(){

    int arr[] = {0,0,0,0,1,1};
    int arr2[] = {0,0,0,0};
    int arr3[] = {1,1,1,1};


    printf("\nTransition Point of array1: %d\n", TransitionPoint(arr, 6));
    printf("\nTransition Point of array2: %d\n", TransitionPoint(arr2, 4));
    printf("\nTransition Point of array3: %d\n", TransitionPoint(arr3, 4));
}