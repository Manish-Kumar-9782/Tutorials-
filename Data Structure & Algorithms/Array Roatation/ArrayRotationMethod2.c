// In this program we will rotate an array using one by one element method.
// In this we will rotate an array with single element in every iteration.
#include<stdio.h>

// To rotate the single element we need to make a function.

void RotateOne(int arr[], int ArraySize){
    /*
    arr: one dimensional array.
    ArraySize: it is the max size of the array element can be presented in a array.
    */

   int i, temp;
   /*
   i: counter variable.
   temp: temp varaible to hold the element which is going to be rotated.
   */

  temp = arr[0]; // first of all copy the very first element into the temp variable.

  // Now left shit every element by one.
  for(i=0; i<ArraySize; i++){
      arr[i]= arr[i+1];
  }
  
  // Now we need to put the temp element at the last position of the array.
  arr[ArraySize-1] = temp;

}

// Now we need to make a function to rotate the array.

void ArrayRotate(int arr[], int ArraySize, int RotateUpto){

    /*
    arr[]: it is the array which is going to be roatated.
    ArraySize: it the size of the array which is going to be passed inside the function.
    RoatteUpto: This parameters is used to define that how much element need to be rotated.
    */

   int i; // Counter variable

   // Now we need to rotate every element one by one.

   for(i=0 ; i<RotateUpto; i++){
       // this will rotate the array evrery iteration by single element.
       RotateOne(arr, ArraySize);
   }
}



void ArrayPrint(int arr[], int ArraySize){

    /*
    arr: it is the array which is need to be printed.
    ArraySize: it is the size of the array.
    */
   int i;
   for(i=0; i<ArraySize; i++)
    printf("%d ", arr[i]);

}

// here Now we will make the main function and in this function we will call the Roatation function to rotate the array.
void main(){

// Declaring the array.

int arr[] = {1,2,3,4,5,6,7,8,9,0};

printf("Array before the Rotation: ");
ArrayPrint(arr,10);

ArrayRotate(arr, 10, 3);

printf("\n\nArray after the Rotation: ");
ArrayPrint(arr,10);

}