/* In this section we will make a program which will be used to create a circular linked listand perfom some
    operation on this circular linked list.

    Note: The only difference in A Linked List and Circular Linked List is that head and last node points to same node
        or we can say that they both points to the head node.
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{

    int data;
    struct Node *next;
};

struct CLinkedList{

    struct Node *head; // To maintain the first node. 
    struct Node *tail; // To maintain the last node 
    int length;

    // 0. A function pointer pointing to a display function.
    void (* display)(struct CLinkedList*);

    // 1. A function pointer pointing to a append function.
    void (* Append)(struct CLinkedList* , int);

    // 2. A function pointer pointing to the InsertFirst Function.
    void (* InsertFirst)(struct CLinkedList*, int);

    // 3. A function pointer pointing to the Insert Function.
    void (* Insert)(struct CLinkedList*, int,int);

    // 4. A function pointer pointing to the DeleteFirst function.
    void (* DeleteFirst)(struct CLinkedList*);

    // 5. A function pointer pointing to the DeleteLast function.
    void (* DeleteLast)(struct CLinkedList*);

    // 6. A function pointer pointing to the Delete function.
    void (* Delete)(struct CLinkedList*, int);

    // 7. A function pointer pointing to the Reverse function.
    void (* Reverse)(struct CLinkedList*);
};

// 0. A function to display elements of the circular linked list.
void display(struct CLinkedList *list){

    /*
        list: LinkedList variable which need to be display.
    */

   if(list->head != 0){

       struct Node *current= list->head;

       printf("\nLinkedList: {");

       while(current->next != list->head){
            printf("%d,", current->data);
            current = current->next;
            // sleep(1);
       }
       
       printf("%d", current->data);
       printf("}\n");
   }
   else
    printf("\nLinkedList : {Empty}\n");
}

// 1. A function to InsertFirst. 
void InsertFirst(struct CLinkedList *list, int value){

    // Inserting at first position.
    
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = list->head;
    list->head = newnode;
    list->tail->next = list->head;
    list->length++;

}

// 2. A function to append an element at the last of the linked list.
void Append(struct CLinkedList *list, int value){

    // appenging an element at the last of the list.

    if(list->head != 0){
        struct Node *current = list->head;

        while (current->next != list->head)
        {
            current = current->next;
        }

        // Now after reaching at the end of the linked list we need to make a new node.
        struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
        list->tail = newnode;
        // now we need to attach all the new node links.
        newnode->data = value;
        newnode->next = list->head;
        current->next = newnode;
    }
    else{
        InsertFirst(list,value);
    }
    list->length++;
    
}

// 3. A function to insert a node at a specific position.
void Insert(struct CLinkedList *list, int value, int pos){

    // Inserting a node at any specific position.
    if(list->head != 0){
        if(pos == 0){
            printf("\nInsertFirst Called\n");
            list->InsertFirst(list, value);
        }
        else{
            printf("\nInserting at i-th Position\n");
            int i;
            struct Node *prev, *current = list->head;

            for(i=0; i<pos; i++){
                
                if(current->next != list->head){
                    prev = current;
                    current = current->next;
                }
                else break;
            }
            printf("\nPos = %d       i = %d\n", pos, i);
            if(current->next == list->head && pos > i+1){
                printf("\nError: Invalid Position %d Out of bound..\n", 7);
                return;
            }

            if(current->next == list->head && pos == i+1){
                printf("\nAppend Called\n");
                list->Append(list, value);
            }
            else{
                struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
                prev->next = newnode;
                newnode->next = current;
                newnode->data = value;
                list->length++;
            }
        }
    }   
    else{
        InsertFirst(list, value);
    }
}

// 4. A function to delete the first element.
void DeleteFirst(struct CLinkedList *list){

    // Deleting the first element

    if(list->head !=0){
        struct Node *temp = list->head;
        list->head = list->head->next;
        list->tail->next = list->head;
        free(temp);
        list->length--;
    }
    else{
        printf("\nError: List Empty..\n");
    }
}

// 5. A function to delete the last element.

void DeleteLast(struct CLinkedList *list){
    
    // Deleting the last element.
    struct Node *temp, *prev, *current = list->head;

    while(current->next != list->head){
        prev = current;
        current = current->next;
    }
    // now current.next will point to the last node.
    temp = current;
    list->tail = prev;
    prev->next = list->head;
    free(temp);
    list->length--;

}

void Delete(struct CLinkedList *list, int pos){

    // Deleting the node from a specific position.

    if(list->head != 0){

        if(pos == 0){
            DeleteFirst(list);
        }
        else{
            
            struct Node *prev , *current = list->head;
            int i;
            for(i=0; i<pos;i++){

                if(current->next != list->head){
                    prev = current;
                    current = current->next;
                }
                else break;
            }

            if(current->next == list->head && pos> i){
                printf("\nError: Invalid Position %d Out of bound\n", pos);
                return;
            }

            if(current->next == list->head && pos == i){
                // Deleting the last node.
                DeleteLast(list);
            }
            else{
                struct Node *temp = current;
        
                prev->next = current->next;
                free(temp);
                list->length--;
            }
        }

        
    }
    else
        printf("\nError: List Empty\n");
}

// 7. Reversal function to reverse the list;
void Reverse(struct CLinkedList *list){

    // This function will be used to reverse the linked list.

    if(list->head != 0){

        struct Node *prev, *current, *next;
        prev = list->tail;
        current = next = list->head;

        while(next->next != list->head){
            next = next->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        current->next = prev;
        list->head = list->tail;
    }
    else
        printf("\nError: List Empty\n");
}

struct CLinkedList *CreateList(int value){
    /*
        Return  type-> struct LinkedList: Since it will return the LinkedList address.
        value: an integer value which will be inserted into the head node.
    */

   // now we need to allocate a memory to the equal to the LinkedList object by using the malloc.
   struct CLinkedList *List = (struct CLinkedList*)malloc(sizeof(struct CLinkedList));
   List->length = 0;
   // after allocating some memory to the linked list we need to add a node into it.
   List->head = (struct Node*)malloc(sizeof(struct Node)); // Since head pointer will hold the head node.
   List->tail = List->head; // Initially tail pointing towards the head node.
   List->head->data = value;
   List->head->next = List->head;
   List->length++;

   // Linking all the operational function.
   List->display = display;
   List->Append = Append;
   List->InsertFirst = InsertFirst;
   List->Insert = Insert;
   List->DeleteFirst = DeleteFirst;
   List->DeleteLast = DeleteLast;
   List->Delete = Delete;
   List->Reverse = Reverse;

   return List;
}


void main(){

    struct CLinkedList *list;

    list = CreateList(10);
    list->display(list);

    // appending new elements;
    list->Append(list,20);
    list->Append(list,30);
    list->Append(list,40);
    list->Append(list,50);
    list->display(list);
    
    // Inserting first at first position.
    list->InsertFirst(list, 60);
    list->display(list);

    // Inserting at a specific position.
    list->Insert(list, 88, 3);
    list->display(list);

    // Deleting the first element;
    list->DeleteFirst(list);
    list->display(list);

    // Deleting the last element;
    list->DeleteLast(list);
    list->display(list);

    // Deleting the i-th node;
    list->Delete(list, 5);
    list->display(list);


    // Reversing the list;
    list->Reverse(list);
    list->display(list);
    printf("\nLength of the list: %d\n", list->length);
}