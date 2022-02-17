// In this section we will make an algorithm of merge sort.

/* Process of merge sort algorithm
1. first of all we need to devide the original array into sub array till single element in each subarray.
2. now we need to sort them.
3. after sorting we need to merge them by using a temp array.

In merge sort array functionallity of the merging is very important so for this algorithm we need to understand the 
    merging procerss.

*/

#include<stdio.h>

void ArrayPrint(int arr[], int ArraySize){

    /*
    arr: it is the array which is need to be printed.
    ArraySize: it is the size of the array.
    */
   int i;
   for(i=0; i<ArraySize; i++)
    printf("%d ", arr[i]);

}

void Merge(int arr[],int lb, int mid, int ub){
    
    /*
    arr: it is the array which will be used in sorting,
    lb: it is the lower bound of the subarray.
    ub: it is the upper bound of the subarray.
    mid: it is the mid point of the sub array from which we will further devide the array.
    */
    int i, j, k;
    i = lb;
    j = mid+1;
    k = lb;

       /*
    i: it is a variable (as pointer) which will point to the left subarray elements.
    j: it is a varaible (as pointer) which will point to the right subarray elements.
    k: it is a variable (as pointer) which will point to the location at which we will insert 
        a sorted eleemnt in a temp array. 
    */

    // Now we will get the size of left and right temp array in which we will copy our original array.
    int n1 = mid - lb + 1; // this is the size of the left sub array.
	int n2 = ub - mid; // this is the size of the right sub array.

    // NOw we will make two temp array in which we will copy our array elements.
    int left[n1]; // left temp sub array
    int right[n2]; // right temp sub array.

    // Now we will copy our original value into the temp array.
    int a; // taking a counter variable.
    
    for(a=0; a<n1; a++){
        left[a] = arr[i+a];
    }

    for(a=0; a<n2; a++){
        right[a] = arr[j+a];
    }

    // Now after copying the values in a temp arrays we need to sort and merge them into original arrays.

    // Now we need to reset the i and j since now we will use i and j for temp array for that i and j will be different
    // and they will be start from 0;
    i=0; 
    j=0;

    // NOte: i and j are the index number so they will start from zero.
    // NOte: n1 and n2 are the array so index number will be less one.
   while(i< n1  && j < n2){
       
       // Now in this loop we will copy our value into original array until above condition becomes False.
       /* Now we will compare left side and right side sub array 
            if left side element is small then we will put the left element into the original array
            other wise we will put the right side sub array element.
       */
       if(left[i] <= right[j]){
           
           arr[k] = left[i];
           i++;
       }
       else{
           arr[k] = right[j];
           j++;
       }
       k++;
   }

    /* 
    Now suppose that our right side sub array do not have more element 
        but left side sub array still have some array so we still do need to put
        those array element into original array.
    */

   while(i < n1){
       arr[k] = left[i];
       i++;
       k++;
   }

    /* 
    Similarly suppose that our left side sub array do not have more element 
        but right side sub array still have some array so we still do need to put
        those array element into original array.
    */
   while(j < n2){
       arr[k] = right[j];
       j++;
       k++;
   }

}


void MergeSort(int arr[], int lb, int ub){
    
    /*
    arr: it is the array which need to be sorted.
    lb: it is the lower bound of the array.
    ub: it is the upper bound of the array.
    */

   // Now if and only if lower bound is less than the upper bound then only we will make a recursion and merging call 
    if(lb < ub){

        // we will devide the array by using the mid point..
        //int mid = lb + (ub-1)/2;
        int mid = (lb+ub)/2;
        
        // left sub array recursion call
        MergeSort(arr, lb, mid);
        
        //right sub array recursion call
        MergeSort(arr, mid+1, ub);
        
        // after splitting all the sub array we need to merge them by sorting element. 
        Merge(arr, lb, mid, ub);
    }
}

void main(){

// Declaring the array.
int n = 10, d = 3;
int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7,1};

printf("Array before the Sorting: ");
ArrayPrint(arr,n);

MergeSort(arr, 0,9);

printf("\n\nArray after the Sorting: ");
ArrayPrint(arr,n);

}