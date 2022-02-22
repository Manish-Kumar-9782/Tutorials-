// In this section we will make a program to Delete a node from a linked list.
// Deletion can be done in three form
/*
1. Delete from begenning
2. Delete from ith position
3. Delete from last node.
*/

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

// Now we will make three individual function to delete a node from a linked list.

/* 1. Delete from Beginning.*/
// First of all we will make a function which will delete the node form the very first node.

void DeleteFirst(struct node **Head){
    // This function will be used to delete the first element (first node) from a linked list.
    
    if(*Head != NULL || *Head != 0){
        // first we will check that Head is not null or empty
        // Now we need to make a temp pointer which will hold the next node location.
        struct node *temp;
        temp = *Head;
        *Head = temp->next;

        free(temp); // Now we deallocate the memory which is contained by the node. 
    }
    else{
        printf("Linked List: [Empty]");
    }
}

/* 2. Delete the last element from a linked list.*/

void DeleteLast(struct node **Head){
    // this function will be used to delete the node from a linked list which is at the last postition.
    struct node *head, *temp, *prevnode;
    /*
    head: will store the address which is holded by *Head.
    temp: it will store the address which is the last node.
    prevnode: it will store the address of last-1 node.
    */
    head = *Head;
    temp = head; // in the beginning we will store the 

    if(head != NULL || head != 0){

        while(temp->next != 0 || temp->next != NULL){
            // now first we will put the temp address into prevnode 
            prevnode = temp;
            // now we need to move to the next node within temp pointer.
            temp = temp->next;
        }
        
        if(head == temp) // if we got temp-next == 0 at very first iteration then this will happen
        {
            // this condition will happen when there is only one node.
            head == NULL; // we will deattach the node first;
        }
        else{
            prevnode->next = NULL; // Assigining NULL to the new last node.
        }
        free(temp);  // then we will delete the node from the memory.
        

    }
    else
    {
        printf("Linked List: [Empty]");
    }
}

/* 3. Deleting a function from any position:*/

void DeleteNode(struct node **Head, int pos){
    /*
    Head: it is a double pointer which will hold the address of the head so we can pass the head by reference
    pos: it is the position of the node which is going to be remove from memory and linked list. 
    */
   struct node *head, *temp, *prevnode;
   int count_node =0; // counter variable which will count the node.
   // Now first of all we will initiate all the pointer
   head = *Head;
   temp = head;
   prevnode = NULL; 

   if(head != 0 || head != NULL){

       if(pos == 0){
           // if we are deleting the first 0th node then we will call DeleteFirst function
           printf("Deleting the 0-th node.\n");
           DeleteFirst(Head);
       }
       else
       {
           // NOw if position is not 0th node then we need to make some logic to track the 
           // prevnode, temp and temp->next node;
        
           for(count_node=0; count_node<pos; count_node++)
           {
               
               if(temp->next != 0 || temp->next != NULL)
               {
                    prevnode = temp;
                    temp= temp->next;
               }
               else
               {
                   printf("Linked List Bound error:\n");
                //    printf("Counted Node: %d\n", count_node);
                   return ; // if we got the bound error then we will retrun to the calling function. 
                   // and we will not go for furthur statement execution.
               }
               
            }

            // after reaching the last-1 node we will link the prevnode with temp.next location
            if(temp->next == 0 || temp->next == NULL)
            {
                // if the pos node is the last node then 
                printf("This is the last element.\n");
                prevnode->next = NULL;
            }
            else
            {
                // if the pos node is not the last node then we will store the temp->next node location in the prevnode.
                printf("this is not the last element.\n");
                prevnode->next = temp->next;
            }
            free(temp);
            

        }

   }
   else{
       printf("Linked List: [Empty]\n");
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
    //append(head, 12);
    //append(head, 56);
    //append(head, 22);


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

    printf("Deleting the 5-th Node: \n");
    DeleteNode(&head, 5);
    PrintLinkedList(head);
    printf("\n\n");

    printf("Deleting the First Node:\n");
    DeleteFirst(&head);
    PrintLinkedList(head);
    printf("\n\n");

    printf("Deleting the Last Node:\n");
    DeleteLast(&head);
    PrintLinkedList(head);
    printf("\n\n");

    printf("Deleting the 1-th Node: \n");
    DeleteNode(&head, 0);
    PrintLinkedList(head);
    printf("\n\n");
    
    printf("Deleting the i-th Node: \n");
    DeleteNode(&head, 0);
    PrintLinkedList(head);
    printf("\n\n");

    printf("Deleting the i-th Node: \n");
    DeleteNode(&head, 0);
    PrintLinkedList(head);
    printf("\n\n");

    printf("Deleting the i-th Node: \n");
    DeleteNode(&head, 1);
    PrintLinkedList(head);
    printf("\n\n");
}