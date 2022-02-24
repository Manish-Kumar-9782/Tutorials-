// In this section we will make algorithm of finding the sub array with given sum;
/*
For example:
1. lets tak a value = 33;
2. then we need to find out the sub array in a array whose elements sum is equal to value;
*/


#include<stdio.h>

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

// Now we will make an algorithm to find out the sub array whose element's sum is equl to our value.
void SubArray(int arr[], int value, int lb, int ub){

    /*
        arr: it is the array in which we need to find the element's whose sum is equal to the given value.
        value: it is the given value of sum;
        lb: it is the lower bound of the sub array.
        ub: it is the upper bound of the sub array.
    */
   if(lb<ub){

        int total=0;
        int i, j;
        i = lb;
        j = ub;
        // first of all we will add first n elements utill their sum is not equl of greater than the value.

        for(; total<value; i++){

            total += arr[i];
            if(total == value)
                printf("sub array index: [%d, %d]", lb, i);
            else if(total > value)
                SubArray(arr, value, lb+1, ub);

        }
    if(lb>ub){
        printf("\nNo sub array presented equl to sum");
    }
   }
}

void main(){

    int arr[] = {1, 4, 20, 3, 10, 5};
    int sum = 5;
    SubArray(arr, sum, 0, 5);

}