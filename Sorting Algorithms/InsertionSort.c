// In this section we will sort an array by using the Insertion Sorting algorithm.


// Insertion Sorting 

/*
    Insertion sort is a simple sorting algorithm that works similar to the way you sort 
    playing cards in your hands. The array is virtually split into a sorted and an unsorted part. 
    Values from the unsorted part are picked and placed at the correct position in the sorted part.
    Algorithm To sort an array of size n in ascending order: 
    
    1: Iterate from arr[1] to arr[n] over the array. 
    2: Compare the current element (key) to its predecessor. 
    3: If the key element is smaller than its predecessor, compare it to the elements before. 
    
    Move the greater elements one position up to make space for the swapped element.
*/


#include<stdio.h>

/*first of all we need to make a swap algorithm which we will swap the array values 
    by using pass by reference method.*/  
void swap(int *a , int *b){
    // *a and *b are the pointer which will hold the array values address 
    // because we will swap the value by using their pointer (indirection operator.)

    int temp = *a;
    *a = *b;
    *b  = temp; 

    // now here we have accessed the values of array by using the indirection operator and swap their values.
    // if you dont know about the pointers and their assignment operation then go and check some tutorial on the C pointers.
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

void InsertionSort(int arr[], int size){
    /*
        int arr[]: This should be an array (integer type array which holds int values.)
        int size: size of the array which is passed in the first argument. 
        (Since in this function we are not calculating the size of the array) 
    */

    // First we will make a loop for a sorted that starts from the zero position and increase as values are in accending order.
    int i,j, key;
    // key:  this will hold one of the swap value.
    
    // we will starts the loop from the second element of the loop.
    for(i=1; i<size; i++){

        // Now we are taking the ith value as key.
        key = arr[i];  // Note: if we are not using the swap function then only this key will be used.
        
        //Now we will initiate the j from i-1 value.
        j = i-1; // in the begining j will be zero which is the last index of sorted array. 
        
        // Now we need to check that ith and (i+1)th values
        // if i+1 value is smaller than ith value then we will swap. 
         /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        
        while(j >=0 && arr[j] > key){
            //arr[j+1] = arr[j];  // swaping the two consecutive values.
            swap(&arr[j], &arr[j+1]);
            j--; // going left in the sorted array.
        }
        //arr[j+1] = key;
    }
   

}



/*==========================================================================================================*/

//Now we will sort an array of 10 values.


int main(){

    system("cls");  // This is used to clear the screen.
    int arr[10] = {4,3,2,10,12,1,5,6,9,8};

    printf("Array before Sorting: ");
    printarray(arr, 10);

    InsertionSort(arr, 10);

    printf("Array after Sorting: ");
    printarray(arr, 10);  

}