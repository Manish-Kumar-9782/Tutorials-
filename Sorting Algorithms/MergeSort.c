// In this section we will make Merge Sorting algorithm and we will see how it works.
/*
Merge Sort is a technique of divide and conqure, it divides the input array into two halves and calls
itself for two halves, and then merge the two sorted merge halves.

The merge() function is used for merging two halves. The merge(arr,l,m,r) is a key
process that assumes that arr[l,m] and arr[m+1,...r] are sorted and merges the two 
sorted sub-arrays into one.

MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = l+ (r-l)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/ 

#include<stdio.h>

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

void merge(int arr[], int lb, int mid, int ub){

    // This is the backbone of MergeSort algorithm in this function will be called after every recursive call of MergeSort;
    // when each sub-array will only have single element then we will merge the sub array.
    
    // first of all we need to make array position variable.
    int i,j,k; 
    // k will track the sorted subarray position.
    // i and j will track the position of the two unsorted subarray position.

    // Now we need to initiate the i, j and k with their initial subarray positon.

    i = lb; // it is th lower bound of left subarray.
    j = mid+1; // it is the lower bound of right subarray.
    k = lb;   // it is the lower bound of sorted array.

    // Here we will make a sub array of size of ub.
    int temparr[10]; 

    // Now we need to check the lower bound and upper bound of each sub array.
    // since i is the lower bound for left sub array and mid is upper bound.
    // j is the lower bound for right sub array and ub is upper bound.
    
    // So we will check that lower bound of each sub array.

    while(i <= mid && j <= ub){
        // if left array's lower bound is less or equal to its upper bound.
        // and if right array's lower bound is less or equal to its upper bound.

        // Now we will check that left value is less or equal
        if(arr[i] <= arr[j]){
            temparr[k] = arr[i];
            // if ith element is less then the jth element.
            i++;
        }
        else
        {
            temparr[k] = arr[j];
            // if jth element is less than the ith element.
            j++;
        }
        // Now after putting the element in the temp array we need to increase its position by one.
        k++; // increasing the position of temp array by one.
    }

    // Now after all of above process there might be some element remaining due to unequal length of the subarray.
    // So now we need to put them also in the sorted array.

    // So Now we need to check that which sub array have extra element by using the mid point.
    // if i>mid; then it means that right subarray have some extra elements.
    // if i<mid; then it means that left subarray have some extra elements.

    if(i>mid){
        // if this happens it means that right subarray have some extra elements
        while (j<=ub)
        {
            temparr[k] = arr[j]; // putting the remaining element at their position
            k++; 
            j++; // increasing the left array position
        }
    }
    else{
        // if above does not happens, it means that left subarray have some extra elements.
        while (i<=mid);
        {
            temparr[k] = arr[i]; // putting the remaining element at their position
            i++; 
            k++;  // increasing the right array position.
        }
        
    }


    /*-----------------------------------------------FINAL OPERATION-------------------------------------*/

    printf("copying element:");
    // after doing all the above operation we need to put all the sorted temp array in the original array.
    for(k=lb; k<=ub; k++){
        arr[k] = temparr[k];
    }
    // copying all the element into the original array.
    printarray(arr, 10);
    printarray(temparr, 10);

}


void MergeSort(int arr[], int lb, int ub){

    /*
        int arr[]: it is the array to be sorted 
        int lb: it is the lower bound of the array
        int ub: it is the upper bound of the array.
    */

   // now first we will check that lb is less than ub or not.
   if(lb < ub){
       // if in our sub array or array, there are more than 1 element then we will divide them.
        // we will divide them by mid point of each sub array for that we need to calculate the middle point.
        int mid = lb + ub/2;  

        // Now we need to make a recursive call for both sub divided array.
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid+1, ub);

        // Now after every sub division of the array we need to merge them by calling merge method.
        merge(arr, lb, mid, ub);
   }
}




void main(){

    int arr[10] = {19,29,34,13,28,87,98,58,49,90};

    printf("Array before Sorting: ");
    printarray(arr, 10);

    // sorting array with MergeSort
    MergeSort(arr,0, 10);

    printf("Array after Sorting: ");
    printarray(arr, 10);


}

