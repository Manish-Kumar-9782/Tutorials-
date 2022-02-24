/* In this section we will make a program in which we will reverse the Linked list.
*/

// first of all we will include required header files.

#include<stdio.h>
#include<stdlib.h>

// Now we will make a struct for the node of the linked list.
struct Node{
    int data;
    struct Node *next;
};
// Now we will make a struct of LinkedList in which we will we will store all the information of linked list.

struct LinkedList{
    struct Node *head; // a head pointer which will contain the head node address.
    int length; // an integer which will contain the current length of the linked list.
    
    // declaring funciton pointer to perform the LinkedList opeartion.
    
    // 0. A function pointer to dispaly the LinkedList.
    void (* display)(struct LinkedList*);

    // 1. A function pointer to append a node at the last position.
    void (* Append)(struct LinkedList*, int);

    // 2. A function pointer to reverse the linked list.
    void (* Reverse)(struct LinkedList*);
};


// 0. A function which will display the linked list.

void display(struct LinkedList *list){

    /*
        list: LinkedList variable which need to be display.
    */

   if(list->head != 0){

       struct Node *current= list->head;

       printf("\nLinkedList: {");

       while(current->next !=0){
            printf("%d,", current->data);
            current = current->next;
       }
       
       printf("%d", current->data);
       printf("}\n");
   }
   else
    printf("\nLinkedList : {Empty}\n");
}

// 1. A function to insert an element at the last position.
void Append(struct LinkedList *list,int value){

    /*
        list: it is the pointer which will pointer towards the struct LinkedList variable.
        value: it the value which will be appeded at the last postion.
    */

   // now we need to firs reach at the last node.
   struct Node *current = list->head;

   while(current->next !=0){
       current = current->next;
   }
   struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
   current->next = newnode;
   newnode->data = value;
   newnode->next = 0;
}

void Reverse(struct LinkedList *list){

    /*
        list: it is the pointer variable which will point towards the LinkedList.
    */
   // This function will be used to reverse the linked list.

   // first of all we need to create the required pointer variable to do this process.
   struct Node *prev, *current, *next;

   /*
    prev: this pointer will point to the previous node which will be behind the current node.
    current: this pointer will point to the current node whose pointing address will be changed.
    next: This pointer will maintain the linked list connection so we dont loss all the link of linked list.
   */ 

   // Now first of all we need to assign 0 to prev node and head to the  current and next node pointer.

   // 1. initiating the perv as 0;
   prev = 0;

   // 2. initiating the current and next node as head
   current = list->head;
   next = list->head;

   // 3. Now we need to traverse through the linked list.
   while(next->next != 0){
    
       // 4. advancing the next node.
       next = next->next;
       // 5. Changing the pointing address of current node.
       current->next = prev;
       // 6. advancing the prev node.
       prev = current;
       // 7. advancing the current node.
       current = next;
   } 
   // 8. Now we need to update the head of the linked list.
   next->next = prev;
   list->head = next; 


}

struct LinkedList *CreateList(int value){
    /*
        Return  type-> struct LinkedList: Since it will return the LinkedList address.
        value: an integer value which will be inserted into the head node.
    */

   // now we need to allocate a memory to the equal to the LinkedList object by using the malloc.
   struct LinkedList *List = (struct LinkedList*)malloc(sizeof(struct LinkedList));

   // after allocating some memory to the linked list we need to add a node into it.
   List->head = (struct Node*)malloc(sizeof(struct Node)); // Since head pointer will hold the head node.
   List->head->data = value;
   List->head->next = 0;
   List->length++;

   // Linking all the operational function.
   List->display = display;
   List->Append = Append;
   List->Reverse = Reverse;
   
   return List;
}


void main(){

    struct LinkedList *List;

    List = CreateList(15);

    // Now we will append some element before the reversal 
    List->Append(List, 34);
    List->Append(List, 45);
    List->Append(List, 67);
    List->Append(List, 78);

    List->display(List);

    // Now we need to reverse the Linked List.
    List->Reverse(List);
    List->display(List);
    
}