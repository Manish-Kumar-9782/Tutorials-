// In this section we will make a program or algorithm which will help us to insert values in an array.

#include<stdio.h>

void insert(int arr[], int *size, int value, int pos,int arr_size){

    /*
        arr[] : it is the array in which we will insert a value.
        *size : it is a pointer which will store the address of the size (how many value are assigned or inserted in the array) 
                Note the size and pointer size are not same.
        value : the value which is needed to insert in the array.
        pos   : position at which we want to insert the new value, Note that pos is index + 1.
        arr_size: To store the size of the full array.
    */
    // Now first of all we need to swap all the value which are in the way of loosing data.
    // means there might be some value which can loos during the assignment.

    /*  suppose that at position 3 there is an existing value and if we want to insert a new value at position 3
        then previous value will be discarded if we dont put it next (4th) position, but the value available at 4th position 
        will be discraded if we dont move it to 5th position it will be going on until we dont have a blank location where we can
        put our new value.
    */

   /*   Swaping or moving of the values in the array will be from right to left.*/

   int i; // a variable (counter varialbe for for-loop)

   // first of all we will get the array size.
   if(pos <= arr_size && pos>0){

        // Now if our position has not reachead to overflow of the array then we need to check that size and pos
        if(*size >= 0 && *size!=arr_size){
            // if our array is not full

            for(i=*size-1; i>=pos-1; i--)
                arr[i+1] = arr[i];  // moving all values to left in the array utill we dont reach to the pos.

            arr[pos] = value;
            *size = *size+1; // now here we need to increase the size (number of element present in the array).
        }
        else    
        {
            // if our array is full
            printf("\nArray is full can't insert more elements.\n");
        }

   }
   else if(pos < 0)
        printf("Invalid Position!..");
   else 
    printf("\nOverflow to array memory.\n");
}


/* Note this method is only for the unsorted array, if we have an unsorted array then 
     best option to insert an item in an array is this function.*/
void insert2(int arr[], int *size, int value, int pos,int arr_size){

    /*
        arr[] : it is the array in which we will insert a value.
        *size : it is a pointer which will store the address of the size (how many value are assigned or inserted in the array) 
                Note the size and pointer size are not same.
        value : the value which is needed to insert in the array.
        pos   : position at which we want to insert the new value, Note that pos is index + 1.
        arr_size: To store the size of the full array.
    */
    // Now first of all we need to swap all the value which are in the way of loosing data.
    // means there might be some value which can loos during the assignment.

    /*  suppose that at position 3 there is an existing value and if we want to insert a new value at position 3
        then previous value will be discarded if we dont put it next (4th) position, but the value available at 4th position 
        will be discraded if we dont move it to 5th position it will be going on until we dont have a blank location where we can
        put our new value.
    */

   /*   Swaping or moving of the values in the array will be from right to left.*/

   int i; // a variable (counter varialbe for for-loop)

   // first of all we will get the array size.
   if(*size >= 0 && *size<=arr_size){

        // Now if our position has not reachead to overflow of the array then we need to check that size and pos
        if(pos > 0 && pos <=*size){
            
            // first of all we will move the postion's value at elements size+1 position;
            arr[*size] = arr[pos-1]; 
            // Now we will put the new value at the poistion.
            arr[pos-1] = value;
            *size = *size+1; // now here we need to increase the size (number of element present in the array).
        }
        else    
        {
            // if our array is full
            printf("\nArray is full can't insert more elements.\n");
        }

   }
   else if(pos < 0)
        printf("Invalid Position!..");
   else 
    printf("\nOverflow to array memory.\n");
}

void printarray(int arr[], int size){
    // to print the array
    int i;
    printf("\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main(){

    int arr[10];
    int input_size=0;

    // suppose that our array is half filled with some defined value.
    arr[0] = 10;
    arr[1] = 15;
    arr[2] = 12;
    arr[3] = 19;
    arr[4] = 17;
    // now here we need to update the input_size as 5.
    input_size = 5; // since we have assigned 5 values form 0-4.
    // Now we want to insert some more values inside the array.
    // insert means putting some value inside the array without lossing the existing value.
    printarray(arr, input_size);
    insert2(arr, &input_size, 100, 3, 10);
    printarray(arr,input_size);

    insert2(arr, &input_size, 58, 1, 10);
    printarray(arr,input_size);
    
    insert2(arr, &input_size, 36, 5, 10);
    printarray(arr,input_size);

    insert2(arr, &input_size, 85, 8, 10);
    printarray(arr,input_size);

    insert2(arr, &input_size, 75, 7, 10);
    printarray(arr,input_size);

    // insert after array is fulled.
    printf("\ninput_size: %d\n", input_size);
    insert2(arr, &input_size, 200, 0, 10);
    printarray(arr,input_size);



}