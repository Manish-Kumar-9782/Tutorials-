// In this section we will make an algorithm which will help us to find out an element from an sorted array.

/* Working of Binary Search:
1. we will find out the mid point of the array.
2. if mid value is equal to the our value then we will return the mid point index.
3. if we don't find out our value in above case then we will devide the array in two sub array left and right.
3. Since our array is sorted, so left array will have the smaller value then the mid point value
    and right array will have the greater value then the mid point.
4. if test value is samller then the mid value then we will make a recursion call with left sub array.
5. if test value is greater then the mid value then we will make a recursion call with right sub array.
6. Now again we will test for the mid point value with test value and repeate all the above process from 2 to 5.

*/
#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int arr[], int n){

    int i;
    printf("Array: [");
    for(i=0; i<n; i++){
        if(i != n-1)
            printf("%d,", arr[i]);
        else
            printf("%d", arr[i]);
    }
    printf("]");
}

int partition(int arr[], int lb, int ub){
    
    /*
    arr: it is the array which will be partitioned in sub array.
    n: it is  the size of the array.
    lb: it is the lower bound of the sub array.
    ub: it is the upper bound of the sub array.
    */

   if(lb < ub){
       
       // now we need a pivot point 
       int i,j;
       i = lb;
       j = ub;
       int pivot = lb; // we are making the lb index as the pivot 

       while(i < j)
       {
            while(arr[i] <= arr[pivot])
            {
                i++;
            }
            while(arr[j] > arr[pivot])
            {
                j--;
            }
            if(i < j)
            {   
                swap(&arr[i], &arr[j]);
            }
           
       }
       if(i > j){
           swap(&arr[pivot], &arr[j]);
           
       }
       return j;
       
   }
}

void QuickSort(int arr[], int lb, int ub){

    /*
        arr: it is the array which is need to be sorted.
        lb: it is the lower bound of array.
        ub: it is the upper bound of array.
        mid: it is the mid point of the new subarray.
    */

   if(lb < ub){

       int pivot;

       pivot = partition(arr, lb, ub);
       QuickSort(arr, lb, pivot-1);
       QuickSort(arr, pivot+1, ub);
   }
}


// Now after sorting we will perform the binary Search on the sorted array.
int BinarySearch(int arr[], int value, int lb, int ub)
{
    /*
    arr: it is the array in which we need to find our value;
    value: it is the value which is need to search in the array.
    lb: it is the lower bound of the array.
    ub: it si the upper bound of the array.

    return: it will return the index of the value if it is present in the array else it will return -1;  
    */

   if(lb <= ub){
       // if lb < ub then it means that we have more then one element in our sub array.
        int mid = (lb + ub)/2;
        printf("\nlb: %d\n", lb);
        printf("ub: %d\n", ub);
        printf("Mid Point: %d\n", mid);

        if(arr[mid] == value){
            // if in our sub array we found our value at the mid point we need to return it.
            return mid;
        }
        else if(value > arr[mid]){
            printf("\nGoing to left side.");
            // if our value is greater than the mid value then, it is sure that our value may be presented at right side of the 
            // sub array mid point.
            lb = mid+1;
        }
        else
        {
            printf("\nGoing to right side.");
            // if our value is less than the mid value then, it is sure that our value may be presented at left side of the 
            // sub array mid point.
            ub = mid-1;
        }
        // Now we need to make a recursion call to find the value in the sub array.
        BinarySearch(arr, value, lb, ub);
   }
   else{
       return -1;
   }
   // if we don't found desired value then we need return -1;
    
   
}

void main(){

    int arr[] = {10,34,45,68,82,98,234,345};
    int value = 0;
    int value_index = 0;

    printf("\n\n");
    PrintArray(arr, 8);
    printf("\nSearching %d. \n", value);
    value_index = BinarySearch(arr, value, 0, 7);
    printf("\nvalue Index: %d\n", value_index);
    
    if(value_index != -1){
        printf("Found at %d .", value_index);
    }
    else
        printf("Not Found");
}
