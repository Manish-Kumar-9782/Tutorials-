// In this section we will see that how can we create a linked list and display its element by iterative method.

/* Linked List:

Since Linked List is made of nodes so to create nodes in c language we will use structure to make a node 
In Singly linked list Node will have two things.

1. Data varibale: a variable which will hold the data.
2. Pointer variable: a pointer which will point to next available node.  
*/

#include<stdio.h>
#include<stdlib.h>

// so to create a node we will use structure as a name of node.

struct node{

    int data; // In this we will store integer typde data.
    struct node *next; // a pointer variable which data type is struct node since it will point to the next node.
    // So do to this pointer should know that what type of data it will point.
};

// Now above code is simple template and it does not create consume memroy untill we dont make any variable.

/* Note: in Linked we always need a head pointer which will store head node of the linked list so for that we need
    to create a pointer as data type of struct node which will hold address of the head node.
*/

void main(){

    // creating a head pointer as data type of struct node.

struct node *Head, *current; 

Head = 0; // initiating the head pointer with null value.

// newnode: in newnodw pointer we will store our very first node.

/* Now after creating the head pointer we need to assign a memory address in head pointer so it can point to the very first node.
    To do this we need to allocate a memory block equal to the size of a single node.
    and we will assign its initial memeory address to the head node
    in this way we can create our first node.
*/

current = (struct node *)malloc(sizeof(struct node)); // creating a memory block equal to the size of a single node.

// NOte: malloc function will return a void pointer, it means it does associate with any data type.
// Since it returns a void pointer we need to make type casting so our pointer could know that we are dealing 
// which kind of data type.


// NOw our newnode pointer contain the very first node address, and now we need to fill a data in it.

// here also we need to assigne very first node address into head pointer so we can access our linked with head node.
Head = current; // since newnode is containing the very first node address.

current->data = 5;
current->next = 0;

printf("\n\nAddress of the very first node: %p", Head);
printf("\nData Stored at the very first node: %d", Head->data);

printf("\n\n"); 
}
