// Array is a derived data types in c array can be declare by using the subscripts [] bracket in variable. name.
// Definition: Array is a collection of same data type, which allocates the memory for data in sequential order.
// if our array is int data type then we cannot put float value in this.

#include<stdio.h>

void main(){

    // declaration of the array.
    int value[5];
    char name[13];
    double results[5];
    // here you can see that we can declare any data type of 

    // Initalization of the array.

    // Array can be initalized at compile time or at run time.

    /*------------------------------------------COMPILE TIME INITIALIZATION-----------------------------------------*/

    // in this we initialize the array during the declaration.
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    // we can also initialize it without specifying the size of the array.
    int arr2[] = {1,2,3,4,5,6,7,8,9,49,39};

    // character array can also be defined as 
    char Name1[] = {'m','a', 'n', 'i', 's', 'h'};
    // or we can do this also.
    char Name2[] = "manish";

    // we need a counter variable for for-loop
    int i;

    /*-----------------------------------------RUN TIME INITIALIZATION-------------------------------------------------*/

    // in this initialization we initialize the array during running the program by inputing from the user.
    // all of the above three array declaration can be initialized during run time.

    // run time initialization of 
    printf("Enter 5 values: ");
    for(i=0; i<5; i++)
        scanf("%d", &value[i]);

    // run time initialization of name array.
    printf("Enter your Full Name: ");
    for(i=0; i<13; i++)
        scanf("%c", &name[i]);

    
    // run time initialization of results.
    printf("Enter Your 5 results: ");
    for(i=0; i<5; i++)
        scanf("%lf", &results[i]); 


    /*------------------------------------------PRINTING ALL THE ARRAY (TRAVERSAL OPEARATION)---------------------------------*/

    // Note: We should note the printing every element by visiting to them, 
    // visiting to each element is called traversal operation on the array.  

    // printing value array.
    printf("\n You Have entered: ");
    for(i=0; i<5; i++)
        printf("%d ", value[i]);

    // printing name array.
    printf("\n You have Enter your name: ");
    for(i=0; i<13; i++)
        printf("%c", name[i]);

    // printing results
    printf("\n Your results: ");
    for(i=0; i<5; i++)
        printf("%.3lf  ", results[i]);

    // printing arr
    printf("\n arr: ");
    for(i=0; i<10; i++)
        printf("%d ", arr[i]);

    // printing arr2
    printf("\narr2: ");
    for(i=0; i<11; i++)
        printf("%d ", arr2[i]);

    // printing Name1
    printf("\nName1: ");
    for(i=0; i<6; i++)
        printf("%c", Name1[i]);

    // printing Name2
    printf("\nName2: ");
    for(i=0; i<6; i++)
        printf("%c", Name2[i]);
}