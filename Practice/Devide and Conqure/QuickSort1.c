// In this section we will make quicksort algorithm

#include<stdio.h>
#include<time.h>  // we will use sleep method to visulize the process of sorting.

void ArrayPrint(int arr[], int ArraySize){

    /*
    arr: it is the array which is need to be printed.
    ArraySize: it is the size of the array.
    */
   int i;
   for(i=0; i<ArraySize; i++)
    printf("%d ", arr[i]);

}

void swap(int *a, int *b){

    /*
    a: Pointer to hold the address of the first element.
    b: Pointer to hold the address of the second element.
    */

   // by using this function we will swap to element by using their address reference.

   // first of all we will make a temp variable which will hold one of the variable value.

   int temp = *a; // passing the value contained by the address which is hold by the pointer a.
   *a = *b;
   *b = temp;

    // above statement will swap the element by using their address.
}

int partition(int arr[], int lb, int ub){
    /*
    arr: it is the array which is going to be devided into parts.
    lb: it is the lower bound of the array.
    ub: it is the upper bound of the array.
    */

   // Now we need to get the pivot element
   int PivotIndex = lb;
   int pivot = arr[lb]; // we are taking first element as the pivot element.

   int start, end; 

   start = lb; // initiating the start with lower bound;
   end = ub; // initiating the end with upper bound;
   /*
   start: this variable will be used to check the elements from left to right. 
          (with this we will check if any value is greater than the pivot value.)
   end: this variable will be used to check the elements from right to left.
          (with this we will check if any value is less than the pivot value.)

    Now if we found greater value with start and less value with end operator (variable) we will swap them.
   */

  // Now we will make a for loop to make a partition array.
    while(start<=end){
        // we will run this loop until the start operator becomes greater than the end operator.

        
        while(arr[start] <= pivot){
            // Moving towards right untill we dont get an element which is greater than the pivot.
            start++;
        }

        while(arr[end] > pivot ){
            // Moving towards left until we dont get an element which is less than the pivot element.
            end--;
        }

        
        if(start < end){
            // Now if our start operator is less than the end operator than we will swap otherwise we don't need swap.
            swap(&arr[start], &arr[end]);
            printf("     swapping");
        }
        sleep(1);
        printf("\n\n start: %d   end: %d    ", start, end);
        ArrayPrint(arr, ub+1);
        
    }
    // Now at the end we need to swap the pivot element with end operator.
    if(start > end){
        printf("   Swapping the pivot element.");
        swap(&arr[PivotIndex], &arr[end]);
    }

    // Now we need to return the  point which devide the array into two parts form pivot point which is the index of end operator. 
    return end;
}   


// here Now we will make the main function and in this function we will call the partition function to sort the array.


void QuickSort(int arr[], int lb, int ub){

    /* In this we will devide an array into sub array and in this all the element right to the pivot element will be greater
        than the pivot element, and left element will be less than the pivot element.

        arr: it is the array which is need to sorted.
        lb: it is the lower bound of the array or subarray in recursion call.
        ub: it si the upper bound of the array or subarray in recursion call.
    */

   // Now first of all we need to make the partition by using the pivot element.

    if(lb< ub){

        int PartitionPoint = partition(arr, lb, ub);
        // partition function will convert the array into two parts and it will return the PartionPoint.
        // Now we need to devide our array into two parts from Partion Point.

        QuickSort(arr, lb, PartitionPoint-1); // left part of the array.
        QuickSort(arr, PartitionPoint+1, ub); // right part of the array.

        // Note that we will not cont the element which is placed at the Partition Point 
        // this element is on right position.
    }


}

void main(){

// Declaring the array.
int n = 9, d = 3;
int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};

printf("Array before the partition: ");
ArrayPrint(arr,n);

QuickSort(arr, 0, 8);

printf("\n\nArray after the partition: ");
ArrayPrint(arr,n);

}