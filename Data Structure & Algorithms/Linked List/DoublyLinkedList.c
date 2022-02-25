// In this section we will make doubly linked list.

/*
    A standard Doubly linked list Node contain three main parts:

    1. data: a data variable in which we can store the data.
    2. prev: a pointer variable in which we will store the address of previous node to current node.
    3. next: a pointer varaible in which we will store the address of next node.
*/


// first we will include all the required header files.

#include<stdio.h>
#include<stdlib.h>

// Now we will create a struct for the Node.

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Now we will create a struct for the doubly linked list in which we will store the information of list.
struct DLinkedList{
    
    struct Node *head; // a pointer which will points towards the head node.
    struct Node *tail; // a pointer which will points towards the last node.

    // Function pointers:

    // 0. Dispaly function pointer
    void (* Display)(struct DLinkedList*);

    // 1. Insert at beginning function pointer
    void (* InsertFirst)(struct DLinkedList*, int);

    // 2. Appending a new node at last of list.
    void (* Append)(struct DLinkedList*, int);

    // 3. A function pointer of a Inserting function at specific position.
    void (* Insert)(struct DLinkedList*, int , int);

    // 4. A function pointer of a deleting function from first position.
    void (* DeleteFirst)(struct DLinkedList *);

    // 5. A function pointer of deleting funtion from last position.
    void (* DeleteLast)(struct DLinkedList *);

    // 6. A function pointer of deleting function from a specific position.
    void (* Delete)(struct DLinkedList *, int);

    // 7. A function pointer of Reversing function.
    void (* Reverse)(struct DLinkedList*);
};

// 0. A functio to dislplay the linked list.
void Display(struct DLinkedList *list){

    // This function will be used to Display the list.

    struct Node *temp = list->head;
    
    if(temp != 0){
        
        printf("\nDLinked List: {");
        while(temp != 0){

            if(temp->next == 0){
                printf("%d", temp->data);
            }
            else
                printf("%d,", temp->data);
            
            temp = temp->next;
        }
        printf("}");
    }
    else
        printf("DLinked List: {Empty}");
}

// 1. A function to add a new node a beginning.
void InsertFirst(struct DLinkedList *list, int value){

    // This function will be used to insert a new node at the first position.
    struct Node *temp = list->head;
    
    if(temp != 0){

        // Now first of all we need to create a new node.
        struct Node *new = (struct Node*)malloc(sizeof(struct Node));

        // first store the data 
        new->data = value;

        // Now link the prev and next pointers.
        new->next = temp; // since this  node is placed at the beginning of the list.
        new->prev = 0;
        temp->prev = new;

        // Now we need to update the head pointer.
        list->head = new;
        
    }
    else{
        list->head = (struct Node*)malloc(sizeof(struct Node));
        list->head->data = value;
        list->head->next = 0;
        list->head->prev = 0;
    }
}

// 2. A function to add a new node at the last of the linked list.
void Append(struct DLinkedList *list, int value){

    // This function will be used to add a new node at the end of the linked list.

    struct Node *temp = list->tail; // this time we will use the tail pointer since it contain the last node address.

    if(temp != 0){
        // Now we need to allocate a new memory block;
        struct Node *new = (struct Node*)malloc(sizeof(struct Node));

        // Now we need to link the new prev pointer to the tail address.
        new->prev = temp; // linking to the prvious last node.
        new->data = value; // assiging value to new node.
        temp->next = new; // linking to the privous last node to the new last node.
        new->next = 0; // Since new last node do not point to next node.
        list->tail = new; // updating the the tail pointer of list.
    }
    else{
        list->InsertFirst(list, value);
    }
}

// 3. a function to add a new node at a specific position.
void Insert(struct DLinkedList *list, int value, int pos){

    // this function will be used to insert a value at specific position.
    struct Node *temp = list->head;

    if(temp != 0){

        if(pos == 0){
            list->InsertFirst(list, value);
        }
        else{
            
            // Now we will create a temp Node pointer which will help us to track the node position.
            struct Node *prev,*temp = list->head;
            int i;
            for(i=1; i<=pos; i++){

                if(temp !=0){
                    prev = temp;
                    temp = temp->next;
                }
                else break;
            }
            // Now we have reached at the specfied position so now we need to create new node memorey block.
            struct Node *new = (struct Node *)malloc(sizeof(struct Node));
            new->data = value; // assigning the value to the new node.

            // Now first of all we need to link it to the prev node and the next node.
            if(temp != 0){
                // it means it we are not working on the last node.
                prev->next = new; // updating the next pointer of prev node.
                new->prev = prev; // updating the prev pointer of new node.
                new->next = temp; // updating the next pointer of new node.
                temp->prev = new; // updating the prev pointer of temp node.
            }
            else{
                // we are appending.
                list->Append(list, value);
            }
        }

    }
    else{
        if(pos == 0)
            list->InsertFirst(list, value);
        else
            printf("Invalid Position.");
    }
}

// 4. A function to delete the first node.
void DeleteFirst(struct DLinkedList *list){
    // This function will be used to delete the very first node of the list.

    struct Node *temp = list->head;

    if(temp != 0){
        // Now we need to shift the head pointer to next node.
        // but first here also we need to check that is there only one node or more then one nodes are present in the list.

        if(temp->next != 0){
            list->head = temp->next; // updating the head pointer.
            list->head->prev = 0; // updating the new head node prev pointer.
            free(temp);  // freeing the memory contain by temp node.
        }
        else{
            // if there is only one node is present 
            list->head = 0;
            free(temp);
        }
    }
    else{
        printf("\nDLinked List :{Emtyp}\n");
    }
    
}

// 5. A function to delete the last node.
void DeleteLast(struct DLinkedList *list){

    // This function will be used to delete the last node of the list.
    struct Node *temp = list->tail;
    if(list->head !=0){

        if(temp->prev != 0){
            list->tail = temp->prev;
        }
        else{
            list->tail = 0;
            
        }
        list->tail->next = 0;
        free(temp);
    }
    else
        printf("\nError: DLinked List is Empty..\n");
}

// 6. A function to delete the node from a specific position.
void Delete(struct DLinkedList *list, int pos){
    
    // This function will be used to delete the node form a specific position.
    struct Node *temp = list->head;

    if(temp !=0){

        if(pos == 0){
            DeleteFirst(list);
        }
        else{
            int i;
            for(i=1; i<=pos; i++){
                
                if(temp != 0){
                    temp = temp->next;
                }
                else break;
            }

            if(temp->next != 0){
                // Now here we need link

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            else
                DeleteLast(list);
        }
        
    }
    else{
        printf("\nError: DLinked List is Empty..\n");
    }
}


// 7. A function to Reverse the doubly linked list.
void Reverse(struct DLinkedList *list){

    /*
    Note: This function will be used to Reverse the Linked List.
    */
   
   // Since it is a doubly linked list so it will have prevnode and nextnode pointer.
   // In simple words we just need to swap the nextnode address value to prevnode value.

   // We will take two pointer to do this job;

   struct Node *current, *Nextnode;
   
   /*
   current: it will do the swapping thing of prevnode value to nextnode value.
   Nextnode: it will maintain the detach link so we dont loss the whole linked list.
   */

  current = Nextnode = list->head;

  // Initially both the nodes are pointing to the same node.

  while(Nextnode != 0){

      Nextnode = Nextnode->next;
      // Since prevnode value does not comes in use while we are traversing from head to tail
      // So first we will update the prev node then after this we will update the next pointer.
      current->next = current->prev;
      current->prev = Nextnode;
      current = Nextnode;
  }
  current = list->head;
  list->head = list->tail;
  list->tail = current;
  // NOw we need to update the tail and head pointes.
}
// Now we will make a function to create the DLinked List.
struct DLinkedList *CreateList(int value){

    /*
        This function will be used to create a double linked list.
        it will create the very first node and put the value in it.
    */

   // Now first of all we will create a new DLinkedList pointer and we will point it to a newly allocated memeory block
   struct DLinkedList *list = (struct DLinkedList* )malloc(sizeof(struct DLinkedList));

   // NOw we will allcoate a new memory block for the first node and link it to the head pointer of the list.
   list->head = (struct Node*)malloc(sizeof(struct Node));
   list->tail = list->head; // initially both pointer will points to the same node.
   // Since it the first node so its prev and next both pointer should contain the zero.
   list->head->next = 0;
   list->head->prev = 0;

   // Now we need to assign the vlaue to the new node.
   list->head->data = value;

   // Now we will all the operation fucntion related to the doubly linked list.
   list->Display = Display;
   list->InsertFirst = InsertFirst;
   list->Append = Append;
   list->Insert = Insert;
   list->DeleteFirst = DeleteFirst;
   list->DeleteLast = DeleteLast;
   list->Delete = Delete;
   list->Reverse = Reverse;

   return list;
   }

   void main(){

       // Now first of all we will create the Linked List pointer variable which will hold the address of list.
       struct DLinkedList *List;

       List = CreateList(10); // initiating a doubly linked list with 10;

       // Now we will dispaly the linked list.
       List->Display(List);

       // inserting at the beginning of the list.
       List->InsertFirst(List, 23);
       List->Display(List);

       // Now we will append a new node at the last of the list.
       List->Append(List, 35);
       List->Display(List);

       // Now we will use th Insert function to insert at specific position.
       List->Insert(List, 42, 1);
       List->Display(List);

       // Inserting at 0-th position
       List->Insert(List, 51, 0);
       List->Display(List);

       // Inserting at last position
       List->Insert(List, 64, 5);
       List->Display(List);

       // Testing the tail pointer
       printf("\nThe Last element of the list: %d\n", List->tail->data);


       //=============TESTING THE DELETE FUNCTIONS===============//
       // Deleting from the beginning
    //    List->DeleteFirst(List);
    //    List->Display(List);

    //    List->DeleteLast(List);
    //    List->Display(List);

    //    List->DeleteLast(List);
    //    List->Display(List);

    //    // Deleting a node from a specific position.
    //    List->Delete(List,0);
    //    List->Display(List);

    //    List->Delete(List,1);
    //    List->Display(List);

    //    List->Delete(List,0);
    //    List->Display(List);

        List->Reverse(List);
        List->Display(List);
   }