// In this section we will make an algorithm in which we will make a stack functionallity by using the linked list concept.
// In this section we will use linked list mechanism to create a stack.

#include<stdio.h>
#include<stdlib.h>

// Now first of all we will make a struct for linked list node.

struct Node{
    // this node will contain two part one is data and another is address of next node.
    int data;
    struct Node *next;
};

// Now we will make a Stack struct which will contain all the information about the stack.
struct Stack{
    struct Node *top; // A pointer which will point towards the top node.
    int Length; // this variable will hold the length of the stack.

    // Now we need to make function pointer which will point to the functions which will perform the stack operations.
    // The reason to link the functions is the we dont need to go anywhere, all the function will come with stack variable.

    // 1. Function pointer to point to create stack function.
    struct Stack* (* CreateStack)(int);

    // 2. Function pointer to point to push function.
    void (* push)(struct Stack*, int);

    // 3. Function pointer to point to pop function.
    int (* pop)(struct Stack*);

    // 4. Function pointer to point to the peek function.
    int (* peek)(struct Stack*);

    // 5. Function pointer to point to the display function.
    void (* display)(struct Stack*);

};

// 1. a function to perform the push operation.
void push(struct Stack *stack, int value){

    /*
    stack: it is a pointer which will point towards the struct Stack data type memory address.
    value: a new value which needed to push into the stack.
    */

    // Now here also we need to make a new node.
    struct Node *newnode = (struct Node* )malloc(sizeof(struct Node));

    // inserting the new value to the new node data
    newnode->data = value;

    // Now we need to swap the address to which our newnode and top are pointing.
    // now newnode will point to the last node which is placed at the top of the stack
    newnode->next = stack->top;
    
    // Now our top pointer will point to the newly created node.
    stack->top = newnode; 

}

// 2. a function to perform the pop operation.
int pop(struct Stack *stack){

    /*
        stack: it will pass a pointer variable of struct Stack variable.
    */

   // Now we need to access the top node and dereference it form the list.
   // after dereference it we need to update the top pointer.
   
   struct Node *temp = stack->top; // it contian the top node.
   int data = temp->data; // storing the data to return it.

   // Now we need to update the top pointer.
   if(temp->next != 0){
       stack->top = temp->next; // if next node points to the another node.
   }
   else{
       stack->top = 0; // if there is no next node.
   }
   // now we need to free the memory which is hold by temp pointer.
   free(temp);

   // now we need to return the data which is poped.
   return data;
}

int peek(struct Stack *stack){

    /*
        stack: a Pointer which points to the struct Stack variable address.
    */

   // In this operation we will only look inside the stack and return the top element placed at the top of the stack.
   struct Node *node = stack->top;
   return node->data;
}

// 4. a function to dispaly the stack 
void display(struct Stack *stack){
    /*
        stack: a Pointer which points to the struct Stack variable address.
    */
    // printf("\ndisplay is called.\n");
    // NOw we need to traverse through all the stack by using the node.
    struct Node *head = stack->top;

    printf("\nStack: {");
    if(head != 0){

        while(head->next !=0){
            // until we don't reach at the last node
            printf("%d,", head->data);
            head = head->next;
        }
        printf("%d", head->data);
        printf("}");
    }
    else
        printf("\nStack: {Empty}\n");
    

}

// 5. A funciton to Initialize the stack.
struct Stack *CreateStack(int value){
    
    /*

    Return Type-> struct Stack*: Since This function will return the address of the newly created stack.
    */
   // Now we will make two variable one from struct Node and one from struct Stack.
   // 1. we will allocate the memory equl to one node into the struct Node variable.

//    printf("\nNew new is creating\n");

   struct Node *newnode =  (struct Node* )malloc(sizeof(struct Node));

   // Now we will make a Stack pointer variable and then we will  link this node to struct Node *top pointer.

    // printf("\nNew stack is creating\n");
    // Now here also we need to create one more memory block in which we will contain all the information about the stack.

   struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
   stack->top = 0; // initially top pointer do not points to any thing.

   newnode->next = stack->top; // now new node does not point to any other node.
   newnode->data = value; // putting the into the newly added node.

   stack->top = newnode; // now top pointer points to the new node.

//    printf("\nLinking all function to stack variable.\n");
   // Now we need to link all the functions.
   stack->display = display;
   stack->push = push;
   stack->pop = pop;
   stack->peek = peek;

   return stack; // returnning the stack
}
// Now we will define a Stack Creating funciton in which we will make a very first node and and 
// we will link all the functionallity of Stack operation.


void main(){

    // Now here we we will create a stack variable.
    struct Stack *stack;

    // first of all we will link the CreatStack fucntion to the stack.
    
    //Testing CreateStack funciton.
    stack = CreateStack(10);

    // Testing display Function.
    stack->display(stack);
    stack->push(stack, 45);
    stack->push(stack, 34);

    printf("\nstack address: %d\n", stack);

    stack->display(stack);

    // Testing peek function.
    printf("\nTop element of Stack: %d\n", stack->peek(stack));

    // Testing pop function. 
    printf("\nTop element of Stack: %d (Removed)\n", stack->pop(stack));

    stack->display(stack);

    // pushing one more element
    stack->push(stack, 67);
    stack->display(stack);


}