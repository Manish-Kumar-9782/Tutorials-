// In this section we will make an algorithm to perfom the stack operation.
// Note: In this section we will use struct and function pointer concept to make the stack functionallity.

/*
A stack operation contain four main funcitonallity.
1. push: it is operation in which we insert a new data at the top of the stack.
2. pop: it is the operation in which we delete and access the data from top of the stack.
3. peek: it is the operation in which we only check that what data is placed at the top of the stack.
4. display: it is the operation in which we traverse through all the stack an display the stack from top to down to user.
*/

#include<stdio.h>
#include<stdlib.h>

// first of all we will make a structure which will control all the operation on the stack.

struct Stack{

    int top; // this is the head of the stack which will show the current top element position.
    int stacksize; // size with we are going to initiate the arr.
    int *arr; // Pointer which will hold the size of array.


    //Note: be carefull here during defining the function pointer variable inside structure
    // We should match all the type casting and also the function arguments types.
    // Now below we will define all the defined function pointer.

    // 1. CreackStack function pointer which will help us to create a new stack which some dynamic memory allocation.
    struct Stack* (* CreateStack)(struct Stack** ,int);
    /*
        1. return type is struct Stack* (a pointer which will return a stack) since it will return the address of the 
            stack varaible.

        2. (* CreateStack) is the name of the function and astrik show that it is pointer.

        3. arguments (struct Stack**, int) defines that this function will be going to tak two variable.
            in which one will take the address of struct stack pointer variable and another (int) show that it
            will receive an integer value.
    */


   // 2. A function pointer which will hold the address of the funtion which will dispaly the stack elements.
    void (* display)(struct Stack *);
    /*
       1. return type void show that the function whose address it will hold does not return any thing.
       
       2. (* display) it is the name of the function pointer which will hold the function address, 
            and we can call that fucntion by using this Name.
       
       3. Argument(struct stack*) show that it will pass address of a struc stack variable. 

    */

   // 3.a function pointer which will hold the address of the function which will add a new element in the stack.
   void (* push)(struct Stack*, int);
   /*
       1. return type void show that the function whose address it will hold does not return any thing.
       
       2. (* push) it is the name of the function pointer which will hold the function address, 
            and we can call that fucntion by using this Name.
       
       3. Argument(struct stack*, int) show that it will pass address of a struc stack variable and one integer value.

    */

   // 4. a function pointer which will hold the address of pop function.
   int (* pop)(struct Stack*);


   // 5. a function pointer which will hold the address of peek function.
   int (* peek)(struct Stack*);

};

// Now first of all we will declare the all the required functions;

// 1. function to make push operation
void push(struct Stack*, int value);

// 2. function to make pop operation
int pop(struct Stack*);

// 3. function to make peek operation
int peek(struct Stack*);

// 4. function to make display operation
void display(struct Stack*);


// 5. To intiate or Create the stack with a defined size.
struct Stack *CreateStack(struct Stack** , int);



void main(){

    struct Stack *init, *Numbers;
    printf("\n In main function.\n");

    init->CreateStack = CreateStack;
    printf("\nNew stack address: %d\n", init);
    Numbers = init->CreateStack(&init,5);
    printf("Numbers Stack address: %d\n", Numbers);
    printf("Size of the New Stack: %d\n", Numbers->stacksize);

    Numbers->display(Numbers);
    // Inserting some elements.
    Numbers->push(Numbers, 7);
    Numbers->push(Numbers, 4);
    Numbers->push(Numbers, 9);

    // Now again we will display the Stack.
    Numbers->display(Numbers);

    // Now we will add one more element;
    Numbers->push(Numbers, 11);

    // Now we will check that what element is present on the top of the stack.
    // it should be 11.
    printf("\nElement at top of stack: %d\n", Numbers->peek(Numbers));
}

/*=============================================================================================================*/
/*===================================MAKING DEFINATION OF DECLARED FUNCTIONS===================================*/
/*=============================================================================================================*/

struct Stack *CreateStack(struct Stack **new_stack ,int size){
    
    // This will be used to create an array with a given size.
    // Size: it is the size of the stack which is going to be created.
    struct Stack *init_stack = *new_stack;
    printf("received stack address: %d\n", init_stack);
    int i; // counter variable.

    printf("\nCreating a new Stack \n");

    init_stack->arr = (int *)malloc(size*sizeof(int));
    init_stack->stacksize = size;
    init_stack->top = -1;

    printf("\nLinking all functions\n");
    init_stack->display = display;
    init_stack->push = push;
    init_stack->pop = pop;
    init_stack->peek = peek;

    // Now we need to set all the variable as 
    printf("\nSetting all stack element as zero. \n");
    printf("Stack size %d\n", init_stack->stacksize);
    for(i=0; i<size; i++){
        init_stack->arr[i] = 0;
    }

    printf("\nReturning the newly created stack.\n");
    // Now we need to return the address of the stack which has been created.
    // Note the 
    return init_stack;
}

void display(struct Stack *stack){

    // this function will hold the stack variable address.
    
    if(stack->top != -1)
    {
        int i;
        printf("\nStack :{");
        for(i=0; i<=stack->top; i++)
        {
            if(i< stack->top)
                printf("%d,", stack->arr[i]);

            else
                printf("%d", stack->arr[i]);   
        }
        printf("}");
    }
    else
        printf("\nStack is on Underflow..\n");

}

void push(struct Stack *stack, int value){
    // this function will be used to insert a new element.


    // first of all we need to check that stack is overflow or not.
    if(stack->top < stack->stacksize-1){
         // Now first of all we need to we need to increase the top postion.
        stack->top++;

        // Now we need to assign the value.
        stack->arr[stack->top] = value;
    }
    else
        printf("Stack is on Overflow, can't add more elements.");
   
}

int pop(struct Stack *stack){
    
    /* this function will be used to get  element is placed at the top of the stack 
        and also it will remove the element from stack.
    */

    if(stack->top != -1){
        // it will check that stack is not on the underflow condition.
        int temp = stack->arr[stack->top];
        stack->top--;
        return temp;
    }
    else
        printf("\nStack is on Underflow..\n");
}

int peek(struct Stack *stack){

    /*
        This function will only used to check that what element is present at top of the stack.
        it will not retrun neither it will change the top variable position.
    */
   return stack->arr[stack->top];
}