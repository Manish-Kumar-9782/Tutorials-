// In this section we will sort an array by using the Bubble Sort algorithm.
/*first of all we need to make a swap algorithm which we will swap the array values 
    by using pass by reference method.*/  

/*
    Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
    Example: 
    First Pass: 
    ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
    ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
    ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
    ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
    Second Pass: 
    ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
    ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
    ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
    Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
    Third Pass: 
    ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 

*/

#include<stdio.h>

// Defining a swap function.
void swap(int *a , int *b){
    // *a and *b are the pointer which will hold the array values address 
    // because we will swap the value by using their pointer (indirection operator.)

    int temp = *a;
    *a = *b;
    *b  = temp; 

    // now here we have accessed the values of array by using the indirection operator and swap their values.
    // if you dont know about the pointers and their assignment operation then go and check some tutorial on the C pointers.
}

// Now we will make a sort function 
void SelectionSort(int arr[], int size){

    /*
        int arr[]: This should be an array (integer type array which holds int values.)
        int size: size of the array which is passed in the first argument. 
        (Since in this function we are not calculating the size of the array) 
    */

   // Now we need to  run a for loop up to size of the array.

    int i,j; // to track the value of loop counter.

    for(i=0; i<size; i++){

        // Now we need to check ith value with jth value, so for that we need to make another loop
        for(j=0; j<size; j++){

            if(arr[i]<arr[j]){
                // Now if our ith value is greater than jth value then we will swap the values.
                swap(&arr[i], &arr[j]);
            }
        }

    }

}


// function to print the array.
void printarray(int arr[], int size){
    // this function will be used to print the one-dimensional array in one line.
    
     /*
        int arr[]: This should be an array (integer type array which holds int values.)
        int size: size of the array which is passed in the first argument. 
        (Since in this function we are not calculating the size of the array) 
    */

   int i; 
   for(i=0; i<size; i++){
       printf("%d ", arr[i]);
   }
   printf("\n");

}

/*==========================================================================================================*/

//Now we will sort an array of 10 values.


int main(){

    int arr[10] = {19, 29,44, 28, 90, 87,45,68,33,10};

    printf("Array before Sorting: ");
    printarray(arr, 10);

    SelectionSort(arr, 10);

    printf("Array after Sorting: ");
    printarray(arr, 10);  

}