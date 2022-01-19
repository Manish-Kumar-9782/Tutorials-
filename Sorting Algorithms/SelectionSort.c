// In this section we will sort an array by using the Selection Sort algorithm.
/*first of all we need to make a swap algorithm which we will swap the array values 
    by using pass by reference method.*/  

// Defining a swap function.

/*
    The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
    from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
    
    1) The subarray which is already sorted. 
    2) Remaining subarray which is unsorted.
    
    In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted 
    subarray is picked and moved to the sorted subarray. 
*/

#include<stdio.h>

void swap(int *a , int *b){
    // *a and *b are the pointer which will hold the array values address 
    // because we will swap the value by using their pointer (indirection operator.)

    int temp = *a;
    *a = *b;
    *b  = temp; 

    // now here we have accessed the values of array by using the indirection operator and swap their values.
    // if you dont know about the pointers and their assignment operation then go and check some tutorial on the C pointers.
}

// Bubble Sort function will tak an array and the size of the array.
void SelectionSort2(int arr[], int size){
    /*
        int arr[]: This should be an array (integer type array which holds int values.)
        int size: size of the array which is passed in the first argument. 
        (Since in this function we are not calculating the size of the array) 
    */
   int i,j=0, min_idx=0;

   // i and j will have the position of the array in both loop
   // min_idx: it is the position of the minimum value in unsorted value.

   // First we need to make a loop which will run upto the size-1 of the array.

   for(i=0; i<size-1; i++){
       // This outer loop will run and track the position of the sorted array.
       // Now we need to make another loop which will run upto the size of the array.

       min_idx=i; // initially we are assuming that ith position is the min_idx;
        for(j = i+1; j<size; j++){
         // finding the minimum element position.
            if(arr[j]<arr[min_idx])
                min_idx = j; // if we found new value which is minimum to the min_idx value then we will
                            // update the min_idx value with j which is the newest minimum vlaue index.

        // Now we have the lowest value index of the array now we will swap the values.
        swap(&arr[i], &arr[min_idx]);

        // Now we will make short unsorted array by one and will increase the sorted array by one.
        // left part will be sorted while right part will be unsorted.
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

    system("cls");
    int arr[10] = {19, 29,44, 28, 90, 87,45,68,33,10};

    printf("Array before Sorting: ");
    printarray(arr, 10);

    selectionSort(arr, 10);

    printf("Array after Sorting: ");
    printarray(arr, 10);  

}