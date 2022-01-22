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

    // first we will make the counter variable that will help us to track the position of left and right subarray 
    int i,j,k;

    // Now we will make to sub array Left and Right of n1 and n2 length
    int n1 = mid-lb+1;
    int n2 = ub-mid;

    // declaring the arrays
    int Left[n1], Right[n2];

    // Now we will copy all the original array element inside these temp Left and Right array.
    
    // Copying left array into temp Left 
    for(i=0; i<n1; i++)
        Left[i] = arr[lb+i];

    // Copying Right array into temp Right
    for(j=0; j< n2; j++)
        Right[j] = arr[mid+1+j];

    
    // Now we need to merge the temp array into arr[lb.....ub];
    i=0; // initial index of first subarray
    j=0; // initial indes of second subarray
    k=lb; // initial index of merged subarray..

    // Now we need to check each value comparing with each subarray.
    while (i< n1 && j< n2)
    {
        if(Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    /* Copying the remaining element of Left subarray if ther are any..*/
    while (i< n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    /* Copying the remaining element of Right subarray if there are any..*/
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
    
}

void merge2(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int lb, int ub){

    /*
        int arr[]: it is the array to be sorted 
        int lb: it is the lower bound of the array
        int ub: it is the upper bound of the array.
    */
   // if in our sub array or array, there are more than 1 element then we will divide them.
        // we will divide them by mid point of each sub array for that we need to calculate the middle point.

   // now first we will check that lb is less than ub or not.
    if(lb < ub){
        int mid = (lb+ub)/2;
        // Now we need to make a recursive call for both sub divided array.
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid+1, ub);

        // Now after every sub division of the array we need to merge them by calling merge method.
        merge(arr, lb, mid, ub);
   }
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


void main(){

    int arr[10] = {10,9,8,7,7,5,4,3,2,1};

    printf("Array before Sorting: ");
    printarray(arr, 10);

    // sorting array with MergeSort
    MergeSort(arr,0, 9);

    printf("Array after Sorting: ");
    printarray(arr, 10);


}

