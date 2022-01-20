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