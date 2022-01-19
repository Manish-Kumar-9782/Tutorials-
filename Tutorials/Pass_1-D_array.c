/* In this section we will see that how to pass a one dimension array to a function.
 there are many situation where we need to pass multiple value for computation.
in this section we will use an example to compute mean and median of 20 values.*/

#include<stdio.h>

/*==========================DECELARATION OF MEAN AND MEDAIN FUNCTION====================================*/

/*Now we will make function to compute the mean and median and also we need a sorting alorithm to do this job.*/

/*Note: if we define all the user-defined function before the main function then we dont need any declaration of any function.*/

void swap(int *a, int *b){

    // Here pointer a and will point to those value which are going to be swap.
    /* Since we cant return the whole array and the stack memory of this function will be deallocated from the system
    so we need to swap them by addressing them so we dont need to modifiy them.*/
    printf("\n\nwe have got two address: %p and %p  and we will swap them\n", a, b);
    printf("These address contain %d and %d values\n",*a, *b);
    int c;
    int temp  = *a; c=*a; 
    printf("\nfirst store %p in temp", a);
    *a = *b;  // since we need to swap the value not the address of the pointer so we need to we astric 
              //to access the the value holding by the pointer.  
    printf("\nNow store b (%p)in a: , temp have: %d", b, temp);
    *b = temp;
    printf("\nNow store temp %d in b: but a have: %p", temp, a);
    printf("\nfinally a have %x and b have %x", a,b);
    
    printf("Value of c is : %d \n", c);
}


int main(){

    system("cls");
    int arr[2] = {100, 200};

    printf("\nbefore swap: a=%d & b=%d", arr[0],arr[1]);

    swap(&arr[0],&arr[1]);

    printf("\nafter swap: a=%d & b=%d", arr[0],arr[1]);

}