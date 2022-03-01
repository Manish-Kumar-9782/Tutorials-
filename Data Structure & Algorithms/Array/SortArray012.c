/* Sort an array of 0s, 1s and 2s: Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

    it means that in an array there are only 0s , 1s, and 2s like this arr[]= {1,0,2,0,1,0,2,0,1,2,0,2};
    In this array there are only values which are greater or equal to 0 and less equal to 2.

    // Now our goal is that we need to sort this array.

    Time Complexity: O(N);
    Auxilary Space: o(1);
*/

/*
Maintain 3 variables low, high and mid
low - all elements before low are 0
mid - all elements between low and mid are 1
high - all elements after high are 2

1.Initially low, mid are set at 0 and high is at n-1

2.Now, we iterate mid from 0 to high, and for every element if it is equal to 0, 
    we swap it with element at low, and increement low and mid.

3. else if it is equal to 2, we swap it with element at high, and decreement high 

4. else we just increement mid (i.e element is equla to 1)

This method ensures partition, as low and high maintain elements according to their values, 
    and then change their positions, ensuring all elements before low are lower than low_value and 
    all elements after high are higher than high_value
*/


#include<stdio.h>
void PrintArray(int arr[], int n){

    // This Metod will used to print the array

    int i;

    printf("\nArray: [");
    for(i=0; i<n; i++){
        
        if(i==n-1)
            printf("%d",arr[i]);
        else
            printf("%d,",arr[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

void Sort012(int arr[], int n){

    int i;
    int low, high, mid;

    low = mid = 0;
    high = n-1; 
    
    for(mid=0; mid<high; ){

        if(arr[mid] == 0){
            swap(&arr[mid], &arr[low]);
            low++;
            mid++;
        }

        else if(arr[mid] == 2){
            swap(&arr[mid], &arr[high]);
            high--;
        }
        else mid++;
    }



}

void main(){

    int n;
    int arr[]= {1,0,2,0,1,0,2,0,1,2,0,2,1,0,1,0,2,1,0,1,0,2,0,1,0,2,0,1,2,0,2,1,0,1,0,2,1,0};

    n = sizeof(arr)/sizeof(arr[0]);


    PrintArray(arr, n);

    Sort012(arr, n);

    PrintArray(arr, n);
}