/* In this section we will make a program in which we will make a linked list and some functionallity of linked
    list like Create, append element, insert at beginning, insert at i-th position, delete form beginning, 
    delete from i-th position, delete from last position, delete last element.
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

    // 1. A function pointer to Insert a node at the beginning.
    void (* InsertFirst)(struct LinkedList*, int);

    // 2. A function pointer to insert a node at i-th position.
    void (* Insert)(struct LinkedList*, int, int);

    // 3. A function pointer to append a node at the last position.
    void (* Append)(struct LinkedList*, int);

    // 4. A function pointer to delete first node of the linked list.
    void (* DeleteFirst)(struct LinkedList*);

    // 5. A function pointer to delete last node of the linked list.
    void (* Deletelast)(struct LinkedList*);

    // 6. A function pointer to delete i-th position node of the linked list.
    void (* Delete)(struct LinkedList*, int);

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

// 1. A function which will insert a node at the beginning.
void InsertFirst(struct LinkedList *list, int value){

    /*
        list: it is the LinkedList pointer variable which will hold the address of the Linked list.
        value: value which will be placed into new node.
    */

   // Now we need to make a new node.
   struct Node *newnode = (struct Node*)malloc(sizeof(struct Node)); // allocating the memory and passing the firs address.
   // Now this newnode will point to the previos node.
   newnode->data = value;
   newnode->next = list->head; // previous node which is pointed by the head.

   // Now we need to update the list head pointer.
   list->head = newnode;
   list->length++;
}

// 2. A function to insert an element at the last position.
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
   printf("\nlast node address: %d", current->next);

   struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
   current->next = newnode;
   newnode->data = value;
   newnode->next = 0;
}

// 3. A function to insert an element at i-th position.
void Insert(struct LinkedList *list, int value, int pos){

    if(pos==0){
        list->InsertFirst(list,value);
    }
    else if(pos>0){

        // Now we need to travers through the list until we dont reach to the position.
        int i;
        struct Node *current = list->head;
        struct Node *prev; // to store the addrsss of prev node.

        for(i=0; i<=pos; i++){

            if(current->next !=0){
                prev = current;
                current = current->next;
            
            }
            else break;
        }

        printf("\ncurrent position index: %d\n", i);
        if(pos == i+1){
            // if we are appending the node at the last position.
            // printf("\n Appending at the end of the node.\n");
            struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
            current->next = newnode;
            newnode->data = value;
            newnode->next = 0;
        
        }
        else if(i<=pos){
            // if our pos is not last or nither we are append at the end of the list.
            // Now after this loop our current will point towards the 'pos-th' element.
            // NOw we need to make a new node.
            struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

            // Now we need to relink our list.
            // 1. Now newnode will point to the current node.
            newnode->next = current;
            newnode->data = value;

            // 2. prev node will point to the newnode node.
            prev->next = newnode;
            // printf("\nCurrent node data: %d\n", current->data);
            
        }
        else{
            // if our position is not the valid position. then we will dispaly the error.
            printf("\nError: Out of bound..\n");
        }
        
    }
    else{
        printf("\nInvalid Position..\n");
    }
}

// 4. A function to delete a node from the beginning.
void DeleteFirst(struct LinkedList *list){
    
    /*
        list: it is the pointer which will point to the LinkedList variable address.
    */
   // Now first of all we need to make a temp node in which we will store the address of the 
   // node which need to removed.

   // we also need to check that list is empty or not.
   if(list->head != 0){
        struct Node *temp = list->head;

        if(list->head->next != 0 ){

            list->head = temp->next;
        }
        else{
            list->head = 0;   
        }
        // Now we need to free the memory.
        free(temp);
   }
   else{
       printf("\nLikedList :{Empty}\n");
   }
   
}

// 5. A function to delete a node form last position.
void Deletelast(struct LinkedList *list){

    /*
        list: it is the pointer which will point to the LinkedList variable address.
    */
    // Now first of all we need to check that our linked list is empty or not.
    if(list->head != 0){

        struct Node *prev, *last = list->head;

        if(list->head->next !=0 ){

            while(last->next !=0){
                prev = last;
                last = last->next;
            }
            prev->next = 0;
        }
        else{
            list->head = 0;
        }
        free(last);
        
    }
    else{
        printf("\nLinkeList: {Empty}\n");
    }
}

// 6. A function to delete a node from i-th position.
void Delete(struct LinkedList *list, int pos){
    
    /*
        list: it is the pointer which will point to the LinkedList variable address.
    */

    if(pos < 0){
        printf("\nInvalid position\n");
        return;
    }

    if(list->head != 0){
        
        if(pos == 0){
            // it means we need to delete the first element.
            printf("\nDeleting the 0-th element\n");
            list->DeleteFirst(list);
            
        }
        else{
            
            struct Node *temp, *prev;
            temp = list->head;
            int i;
            for(i=0; i<pos; i++){

                if(temp->next != 0){
                    prev = temp;
                    temp = temp->next;
                }
                else break;
            }
            printf("\nDeleting %d-th, pointing to %d-th\n", pos, i);
            if(i == pos && temp->next == 0){
                // it means that we want to delet the last element.
                prev->next = 0;
                free(temp);
            }
            else if(i<pos && temp->next !=0){
                // it means that we are not deleting the last element.
                prev = temp->next;
                prev->next =0;
                free(temp);
            }
            else{
                printf("\nError: Out of bound.\n");
            }
        }
        
    }
    else{
        printf("\nLinkedList :{Empty}\n");
    }
    
}
// Now we need to make a function to create a Node and Linked List.
// 4. A function to insert an element at 
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
   List->InsertFirst = InsertFirst;
   List->Insert = Insert;
   List->Append = Append;
   List->Delete = Delete;
   List->DeleteFirst = DeleteFirst;
   List->Deletelast = Deletelast;


   return List;
}

void main(){

    struct LinkedList *List;

    List = CreateList(15);

    // displaying the List;
    List->display(List);

    // Inserting at the beginning
    List->InsertFirst(List, 21);
    List->display(List);

    // testing Insert
    List->Insert(List, 34, 1);
    List->display(List);

    // Now appending at the last position of the list.
    List->Insert(List, 101, 3);
    List->display(List);

    // Now appending at the last position of the list.
    List->Insert(List, 78, 0);
    List->display(List);

    List->Append(List, 12);
    List->display(List);

    // Now we will delete the first element.
    List->DeleteFirst(List);
    List->display(List);

    // Now we will delete the last element.
    List->Deletelast(List);
    List->display(List);

    // Now we will test the Delete 0-th element function.
    List->Delete(List, 0);
    List->display(List);

    // Now we will test the Delete 2-th element function.
    List->Delete(List, 2);
    List->display(List);

    List->Delete(List, 1);
    List->display(List);

    List->Deletelast(List);
    List->display(List);
    
    
}