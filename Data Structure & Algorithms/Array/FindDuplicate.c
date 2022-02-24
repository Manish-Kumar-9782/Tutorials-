// In this section we will make an algorithm which will find out the duplicate value

#include<stdio.h>
#include<stdlib.h>

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

struct duplicates{

    int *duplicate_arr;
    int arr_size;
};

void SetAll(int arr[],int n,int value){
    
    /*
        arr: it is an array in which we need to set all the elements as same value.
        value: set this value to all element.
    */
   int i;

   for(i=0; i<n; i++){
       arr[i] = value;
   }
}

int is_in(int arr[], int n, int value){

    // this function will help us to search and compare the value in two arrays:
    int i;

    for(i=0; i<n; i++){
        if(arr[i] == value){
            return 1;
        }
    }
    return 0;
}

// NOw we will make the find duplicate vlaues.

void *Duplicate(int arr[], int n){

    /*
        arr: array in which we need to find out the duplicate values.
        n: it is the size of the array.
    */
   int i;
   int is_present=0;
   int original[n];
   static int duplicate[10];
   SetAll(original,n, -1);
   SetAll(duplicate,10, -1);



   int k=0,l=0;
   for(i=0; i<n; i++){

       //is_present = is_in(original, n, arr[i]); // searching the value in original 

       if(is_in(original, n, arr[i])){
           // if value is not present in the original value then we will assign it in original array.
           duplicate[k] = arr[i];
           k++;
       }
       else{
           // if value is already presented in the original array then we need to append it into duplicate array.
           original[l] = arr[i];
           l++;
       }

   }
   static struct duplicates dup;
   dup.duplicate_arr = duplicate;
   dup.arr_size = k;
   printf("total duplicate elements: %d", k);
   return &dup;
}

void main(){

    int arr[] = {1,2,4,8,6,2,4,9,3,0,9,4,5,3,5,6,9,3,0};
    int ArSize = sizeof(arr)/sizeof(arr[0]);
    struct duplicates *dup;
    

    printf("\narray Size: %d\n", ArSize);
    dup = Duplicate(arr, ArSize);

    printf("\n\n");
    printf("Original ");
    PrintArray(arr, ArSize);

    printf("\n Duplicate ");
    PrintArray(dup->duplicate_arr, dup->arr_size);

   
    
}