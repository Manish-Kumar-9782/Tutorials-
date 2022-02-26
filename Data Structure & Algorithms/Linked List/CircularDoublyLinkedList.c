// In  This section we will see thae circular doubly linked list an we will see the all the operation 
/*
    Normal operation on the doubly linked list.
    1. Deletion
    2. Insertion
    3. Reversal
    4. Sorting.
    */


#include<stdio.h>
#include<stdlib.h>

// Now first of all we need to make Node struct
struct Node{

    int data;
    struct Node *prev;
    struct Node *next;
};

struct CDLL{
    // CDLL: Circular Doubly Linked LIst.
    struct Node *head;
    struct Node *tail;
    int length;

    // Now we will linke all the operational funciton with the help of the function pointer.

};

// 0. display the element of the linked list.
void Display(struct CDLL *list){

    // This function will be used to display the linked list.
    struct Node *temp = list->head;
    if(list->head != 0){

        printf("\nList: {");

        while(temp->next != list->head){

            printf("%d,", temp->data);
            temp = temp->next;
        }

        printf("%d",temp->data);
        printf("}\n");
    }
    
    else
        printf("\nList: Empty\n");
}

// 1. Inserting an element at the first position
void InsertFirst(struct CDLL *list, int value){

    // this method will add one element at the beginning of the linked list.

    // now we will check that our linked list is empty or not
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;

    if(list->head != 0){
        // it has one or more values
        // Since we are adding an element at the beginning then we need to point our head to the this node.
        // and this node will also point towards the current pointing node by head.

         newnode->next = list->head;  // newnode next pointer will pointing towards the previous head node.
         list->head->prev = newnode; // our previous head node prev pointer pointing towards newnode.
         newnode->prev = list->tail; // new node prev pointer will poin
         list->head = newnode;
         list->tail->next = list->head; // Now our last element will point to the new head node
    }
    else{
        // it does't have any value.
        list->tail = list->head;
        list->head->next = list->head;
        list->head->prev = list->tail;
        

    }
    // Increasing the length by after adding a new element
    list->length++;

}

// 3. Function to insert an element at the last position.
void append(struct CDLL *list, int value){

    // This function will add a new element at the last position.

    if(list->head != 0){

        // Now since we are maintaining the tail pointer so we just need to break the head.prev and tail.next 
        // pointing address and put a new address b/w them.

        struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

        // Now first of all we need to put the value and link it with head and tail.
        newnode->data = value;
        // 1. newnode prev pointer will point to the current tail
        newnode->prev = list->tail;
        // 2. newnode next pointer will point to the current head 
        newnode->next = list->head;
        // 3. Now current tail.next will point to the new node.
        list->tail->next = newnode;
        // 4. Now current head.prev will point to the new node.
        list->head->prev = newnode;
        // 5. now we will update the new tail address
        list->tail = newnode;

        // Increasing the length by after adding a new element
        list->length++;

    }
    else{
        // this means we dont have any value // so we need to add a new value at first position
        // calling InsertFirst.
        InsertFirst(list, value);
    }

}

// 4. Inserting at specific position.
void Insert(struct CDLL *list, int value, int pos){

    // This method will be used to insert an element at a specific position.
    if(list->head !=0){

        if(pos == 0){
            InsertFirst(list, value);
        }
        else
        {
            struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
            struct Node *temp  = list->head;
            newnode->data= value;
            int i;
            for(i=0; i<pos; i++){
                
                if(temp->next != list->head){
                    temp = temp->next;
                }
                else break;        
            }

            // Now we need to check that we are at last position or befor last node.
            printf("\npos = %d      i = %d\n", pos, i);

            if(temp == list->tail && pos == i+1){
                append(list, value);
            }
            else{
                newnode->next = temp;
                newnode->prev = temp->prev;
                temp->prev->next = newnode;
                temp->prev = newnode;

                // Increasing the length of the list
                list->length++;
                
            }

        }
    }
    else{
        if(pos == 0){
            InsertFirst(list, value);
        }
        else
            printf("\nInsertion Denied: Invalid Position %d\n", pos);
    }
}

// 5. A function to delete first value form the list.
void DeleteFirst(struct CDLL *list){

    // This function will be used to delete a value form first position.
    // first we need to check that our list is empty or have some elements
    if(list->head != 0 ){
        
        struct Node *temp = list->head;

        if(list->head != list->tail){
            // it means at least we have two elements.

            list->head = temp->next;
            list->head->prev = list->tail;
            list->tail->next = list->head;
            free(temp);
            list->length--;
        }
        else
            {
                list->head = 0;
                free(temp);
                list->length--;
            }

    }
    else
        printf("\nError: List Empty\n");
}

// 6. Delete last element of the list.
void DeleteLast(struct CDLL *list){

    // This function will delete the last element of the list.

    if(list->head != 0){

        if(list->head != list->tail){

            // now we need to store the tail node into temp
            struct Node *temp = list->tail;

            // Now we need to swap the pointer of the temp.prev node.

            // 1. Now our new tail will be temp.prev
            list->tail = temp->prev;
            // 2. tail.next will point to the list head
            list->tail->next = list->head;
            // 3. head.prev will point to the new tail
            list->head->prev = list->tail;
            // 4. Now free the memory contained by temp
            free(temp);
            // 5. decrease the length
            list->length--;

        }
        else{
            DeleteFirst(list);
        }

    }
    else
        printf("\nError: List Empty\n");
}


// 7. A function to delete a value form a specific position

void Delete(struct CDLL *list, int pos){

    if(list->head != 0){

        if(pos == 0){

            DeleteFirst(list);
        }
        else{

            struct Node *temp = list->head;
            int i;

            for(i=0; i<pos; i++){

                if(temp->next != list->head){
                    temp = temp->next;
                }
                else break;
            }

            if(temp == list->tail && pos == i){
                DeleteLast(list);
            }
            else if (pos < list->length-1){

                // Now or temp is in b/w somewhere first and last element

                // 1. Now temp.prev.next will point to the temp.next;
                temp->prev->next = temp->next;
                // 2. temp.next.prev will point to the temp.prev;
                temp->next->prev = temp->prev;
                // 3. Now we can free the temp 
                free(temp);
                // 4. decrease lenght of list elements
                list->length--;

            }
            else
                printf("\nError: Invalid position %d out of bound \n", pos);
        }

    }
    else
        printf("\nError: List Empty\n");
}

struct CDLL *CreateList(int value){
    // This method will be used too create a circular doubley linked list

    // Now first of all we need to make a Linked List memory block
    struct CDLL *list = (struct CDLL*)malloc(sizeof(struct CDLL));
    list->length = 0;

    // Now since we have the list variable block now we can make a newnode block and link it to the head and tail pointer.
    list->head = (struct Node*)malloc(sizeof(struct Node));
    list->head->data = value;
    list->tail = list->head;
    // Now Since this node contain the prev and next node data 
    // Since this is the only single node so this will contain 0 on the left end and contain head address on rith end.

    list->head->next = list->head;
    list->head->prev = list->tail;
    
    // Increasing the length by after adding a new element
    list->length++;


    //Now we will link all the function with function pointer of this linked list.


    return list;
}

// Now we will call all the function in the main function.

void main(){

    struct CDLL *list = CreateList(10);

    Display(list);

    // Inserting new elements
    InsertFirst(list, 20);
    InsertFirst(list, 30);
    InsertFirst(list, 40);
    Display(list);

    // appending the element at last position.
    append(list, 50);
    append(list, 60);
    Display(list);


    // adding an element at specific position
    Insert(list, 88, 3);
    Display(list);

    Insert(list, 99, 6);
    Display(list);


    // Deleting the first elements
    DeleteFirst(list);
    Display(list);

    DeleteFirst(list);
    Display(list);

    DeleteLast(list);
    Display(list);

    DeleteLast(list);
    Display(list);
    
    Delete(list, 4);
    Display(list);
    printf("\nTail Pointing value: %d\n", list->tail->next->data);
    printf("\nCurrent List length: %d\n", list->length);

}