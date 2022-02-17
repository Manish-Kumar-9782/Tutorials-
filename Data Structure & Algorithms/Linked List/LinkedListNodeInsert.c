// In this section we will make a program to insert a node in link at ith position.

// So first of all we need to make a linked list template by using the structure

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Now we need to make function to print a linked list.

void PrintLinkedList(struct node *head){

    /*
    head: it is the head pointer of node which contains the very first node of the linked list.
    */

   // Now first of all we need to check that head contains the firs node or it has null value.
   if(head != 0 || head !=NULL){
       // if head is not empty then only we will go ahead.
       struct node *current;
       current = head; // Now we will copy our head into current pointer.

       // Now we will check current->next pointer until it does not have 0;
       // setting the format of linked list and packing it into brackets [];
       printf("Linked List: [");
       while(current->next != 0 || current->next != NULL){
           printf("%d, ", current->data);
           current = current->next;
       }
       printf("%d", current->data); // printing the last remaining node which is have 0 or null value.
       printf("]");
   }
   else{
       printf("Linked List: [empty]");
   }
}

void LinkedList(struct node **head, int value){
    // this function will be used to initate the Linked list by creating a very first value and returing its base address.
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node)); // assigning the first empty node address to the head.
    (*head) = newnode;
    newnode->next = NULL;
    newnode->data = value;
    
}

// Now also we need to make another function also which will help us to add new element.

void append(struct node *head, int value){
    
    struct node *current;

    if(head != 0 || head != NULL){
        
        current = head;
        while(current->next !=0 || current->next !=NULL){
            current = current->next;
        }

        // Now after reaching at the end of the linked list we need to add a new node.
        current->next = (struct node *) malloc(sizeof(struct node));

        // Moving to the newlly added node.
        current = current->next;
        current->data = value; // inserting value to the newly added node.
        current->next = NULL; // setting NULL to the 

    }
   
}

// Now we will make an element which will help us to insert an element at ith position.

void insert(struct node **head, int value, int pos){
    /*
    head: a pointer which contain the address of the head of linked list.
    value: integer value which will be inserted in the linked list.
    pos: position at which we want to insert new value. (Note: indexing starts from 0;)
    */

   // first of all we need to make a variable by which we can travers through the list.
   struct node *current, *next_node, *new_node; // current variable for traversing the list.
 
   current = *head;
   if(pos == 0){
        // now allocating new node in current node.
        new_node = (struct node *) malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = *head;
        *head = new_node;

   }
   else{

       if(current->next != 0 || current->next != NULL){
            int current_pos=1;
            while(current_pos < pos){
                    printf("current_pos: %d\n", current_pos);
                    current = current->next; // traversing through linked list until we don't reach upto the postion.
                    current_pos++;
                    if(current->next == 0 || current->next == NULL)
                        break;
                    
            }

            printf("current node value: %d\n", current->data);

            // now after reaching at the position we need to create a new node but first we need to store pos + 1 node in next_node variable.
            next_node = current->next;

            // now allocating new node in current node.
            new_node = (struct node *) malloc(sizeof(struct node));
            new_node->data = value;
            new_node->next = next_node;
            current->next = new_node;

            // NOw we need to move to newly added node make it pointing toward remaining list.
   }
        
   }
   
}
void main(){

    // Now we will make two node variable 
    // head and current node variable.
    struct node *head=NULL;

    // head: head will contain the very first node address;
    // current: it will contain the newly added node address.

    // now we need to create a new node
    LinkedList(&head, 15);  // Initiating the LinkedList by creating the very first node.
    append(head, 10); // appending 10 by creating one more node at the end of the linked list.
    append(head, 12);
    append(head, 56);
    append(head, 22);


    printf("head value: %d", head->data);
    printf("\n\n");
    PrintLinkedList(head);
    printf("\n\n");

    insert(&head, 11, 1);
    PrintLinkedList(head);
    printf("\n\n");

    insert(&head, 20, 0);
    PrintLinkedList(head);
    printf("\n\n");

    insert(&head, 85, 5);
    PrintLinkedList(head);
    printf("\n\n");


}