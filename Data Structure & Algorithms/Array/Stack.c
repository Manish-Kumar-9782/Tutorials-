// In this section we will make a program in which we will make a stack functionallity.
// In this section we only work on the static array.

/*
A stack operation contain four main funcitonallity.
1. push: it is operation in which we insert a new data at the top of the stack.
2. pop: it is the operation in which we delete and access the data from top of the stack.
3. peek: it is the operation in which we only check that what data is placed at the top of the stack.
4. display: it is the operation in which we traverse through all the stack an display the stack from top to down to user.
*/

// Note:  Now in this we will all the operation discussed above by using the functions.
// we will not access the array directly.

#include<stdio.h>
#include<stdlib.h>

// In this section we are defining the size of array by using macros and we will make it constant.
// it means that stack will have a limited size.
#define SIZE 10

int TOP  = -1; // defining the intial position of index;

// The reason behing making top as global is that we need to maintain the top position of the stack
// so we can put data over another data.

// 1. Push fuction
void push(int arr[], int value){

    // Now in this first we need to increase the Top position and insert the value.
    if(TOP<SIZE){
        TOP++;
        arr[TOP] = value;
    }
    else    
        printf("Stack is Overflowed.");
    
}

// 2. Pop function
int pop(int arr[]){

    // Now in this first we need to store the top value in temp and then we need to decreacse the top;
    if(TOP == -1){
        printf("Stack is Underflowed.");
    }
    else{
        int temp = arr[TOP];
        TOP--;
        return temp; // returning the top value of stack.
    }
}

// 3. peek function
int peek(int arr[]){

    // this function will only used to check that what value is stored at the top position.
    return arr[TOP];
}

// 4. display function
void display(int arr[]){

    // this function will be used to travers through all the 
    if(TOP != -1){

        int i;
        printf("\nStack : {");

        for(i=TOP; i != -1; i--){
            
            if(i !=0){
                printf("%d,",arr[i]);
            }
            else
                printf("%d", arr[i]);
        }
        printf("}\n");
    }
    else
        printf("\nStack :{empty}\n");
}

void main(){

   int arr[SIZE]; // SIZE is a global variable and can be used in any other function.
   
   // Initially our stack is empty
   display(arr);
   printf("\n");

   // first we will push a few elements in the stack.

   push(arr, 4);
   push(arr, 8);
   push(arr, 7);
   push(arr, 3);
   push(arr, 9);

// Now we will display the stack.
   display(arr);
   printf("\n");


// Now we will pop top element and we will dispaly it.
   printf("Poping top element: %d\n", pop(arr));
   display(arr);
   printf("\n");

// agian poping top element and we will dispaly it.
   printf("Poping top element: %d\n", pop(arr));
   display(arr);
   printf("\n");

// Now we will only peek this time at the top element.
   printf("peeking top element: %d\n", peek(arr));
   display(arr);
   printf("\n");

}