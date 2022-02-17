#include<stdio.h>

// In this program we will rotate the array by using the temp array. in which...
// 1. First we will copy all the element which are going to be rotated in a temp array.
// 2. second we will shift left element toward right side.
// 3. third we will copy all the element stored inside the temp array at the tail of the original array.

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


void ArrayRotate(int arr[], int ArraySize, int RotateUpto){

    /*
    arr[]: it is the array which is going to be roatated.
    ArraySize: it the size of the array which is going to be passed inside the function.
    RoatteUpto: This parameters is used to define that how much element need to be rotated.
    */

   // Now first of all we will copy all the element which are going to be rotated in the temp arary.

   int temparr[RotateUpto]; // Rotation size is defined in the RotationUpto variable.

   // Now we will copy all element which need to be roate.

   int i,j; // counter variable.

   for(i=0; i<RotateUpto; i++){

       // putting element in the temp array.
       temparr[i] = arr[i]; // all the very first element upto Rotation size.
   }

   // Now we need to left shift the array upto Rotation size.
   for(i=0; i<ArraySize-RotateUpto; i++){

       // Now we will left shift all the other element by Rotation size.
       arr[i] = arr[i+RotateUpto];
   }

   // after shifting we will put all the temp array element in to our original element at the tail of the array.

   for(i=ArraySize-RotateUpto, j=0; i<ArraySize; i++, j++){

       arr[i] = temparr[j];
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