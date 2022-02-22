// In this section we will make a program which will be used to search an element in an array.
/*
Linear Search: 
*/

#include<stdio.h>
#include<stdlib.h>

void PrintArray(int arr[], int n)
{
    /*
        arr: it is the array to be printed:
        n: it is the size of the array.
    */
   int i; // loop counter variable.
   printf("Array: [");
   for(i=0; i<n; i++)
   {
       printf("%d",arr[i]);
       if(i != n-1)
            printf(",");
   }
   printf("]\n");
}

// Now we will make a funciton will search for an element.

int LinearSearch(int arr[],int n ,int value){

    /*
    value: it is the value which is need to be find (search).

    Note: This algorithm will work for both sorted and unsorted array.
    return: it will return the index of the value at which it is founded.
    */
   int i;
   if(n != 0){
       // if array is not empty.
       for(i=0; i<n; i++){

           if(arr[i] == value)
                return i;
       }
       return -1;
   }
}


void main(){
    
    int arr[] = {34, 54, 57, 23, 98, 38};
    int index, value=50; 
    printf("\n\n");
    PrintArray(arr, 6);
    printf("\n\n");

    index = LinearSearch(arr,6,value);

    printf("value is found at %d which is %d", index, arr[index]);
}