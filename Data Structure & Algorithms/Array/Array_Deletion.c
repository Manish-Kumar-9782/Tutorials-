// In this section we will make a program (alorithm) of deleting an item from an array.

#include<stdio.h>

// frist of all we will make a function to print the array
void printarray(int arr[], int size){
    // to print the array
    int i;
    printf("\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// This method is suitable for both unsorted and sorted method. 
void delete(int arr[], int *size, int pos, int arr_size){

     /*
        arr[] : it is the array in which we will insert a value.
        *size : it is a pointer which will store the address of the size (how many value are assigned or inserted in the array) 
                Note the size and array size are not same.
        pos   : position from which we want to delete the value. Note that position in the index is +1 ahead from the index numbring.
                if we want to delete the element at 0th index then we need to pass pos = 1; it means delete the first element.
        arr_size: To store the size of the full array.
    */

   if(*size >= 0 && *size <= arr_size ){
       // if presented elements are greater than 0 and less than or equal to array size

        
        if(pos > 0 && pos <=*size){
            int i;// counter variable for for-loop;
            for(i=pos-1; i<*size; i++)
            arr[i] = arr[i+1];

            // Now we will decrease the elements size.
            *size = *size-1;
        }
        else if(pos >arr_size || pos > *size)
            printf("index is Out of bound!");
        
        else
            printf("Invalid index!");
        

   }
   else if(*size > arr_size){
        printf("Out of bound!");

   }
   else 
        printf("Invalid Size of array!");
}


/* Note this method is only for the unsorted array, if we have an unsorted array then 
     best option to delete an item from the array is this function.*/
void delete2(int arr[], int *size, int pos, int arr_size){

    
    /*
        arr[] : it is the array in which we will insert a value.
        *size : it is a pointer which will store the address of the size (how many value are assigned or inserted in the array) 
                Note the size and array size are not same.
        pos   : position from which we want to delete the value. Note that position in the index is +1 ahead from the index numbring.
                if we want to delete the element at 0th index then we need to pass pos = 1; it means delete the first element.
        arr_size: To store the size of the full array.
    */

   if(*size >= 0 && *size <= arr_size ){
       // if presented elements are greater than 0 and less than or equal to array size

        
        if(pos > 0 && pos <=*size){
            arr[pos] = arr[*size-1]; // swaping the very last element at the defined position. 
            arr[*size-1] = 0; // assigning the blank block as 0
            *size = *size -1; // reducing the elements size in the array by one.
        }
        else if(pos >arr_size || pos > *size)
            printf("index is Out of bound!");
        
        else
            printf("Invalid index!");
        

   }
   else if(*size > arr_size){
        printf("Out of bound!");

   }
   else 
        printf("Invalid Size of array!");


}

void main(){

    int values[10] = {37,28,23,89,90,39,49};
    int el_size = 7;
    // initially our array has filled up to 7 position.

    // Now we want to delete values from some postion, let's say delete 1, 3, 5, position values..

    printf("element size: %d", el_size);
    printarray(values, el_size);

    delete2(values, &el_size, 5, 10);
    printarray(values, el_size);

    printf("element size: %d", el_size);
    delete2(values, &el_size, 3, 10);
    printarray(values, el_size);

    printf("element size: %d", el_size);
    delete2(values, &el_size, 1, 10);
    printarray(values, el_size);

    printf("element size: %d", el_size);
    delete2(values, &el_size, 4, 10);
    printarray(values, el_size);
    printf("element size: %d", el_size);

    // testing of out of bound
    delete2(values, &el_size, 0, 10);
    printarray(values, el_size);
    printf("element size: %d", el_size);

    delete2(values, &el_size, 12, 10);
    printarray(values, el_size);
    printf("element size: %d", el_size);
}