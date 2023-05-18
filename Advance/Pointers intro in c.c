#include<stdio.h>

/*
	In this section we will work on the pointers.
	syntax:
	first we will declare the data type for which we will make our pointer.
	
	int *var; -> astrik declare that this variable is a pointer variable.
*/

struct Node{
	int value;
	struct Node *next;
};

void main(){
	
	// first creating a variable.
	int a = 20;
	
	// now creating a pointer
	int *ptr = &a; // assigning the memory address to the ptr pointer.
	
	// value of a and address of a by using the a variable.
	printf("Value of a: %d\n",a);
	printf("Address of a: %d\n", &a);
	
	
	// value of a and address of a by using the ptr variable.
	printf("address of a from ptr: %d\n", ptr);
	printf("Value of a from ptr: %d\n", *ptr);
	
	
	// Now we will create a simple linked list using Node.
	
	struct Node node1 = {100,0};
	struct Node node2 = {500, 0};
	node1.next = &node2;
	struct Node node3 = {800,0};
	node2.next = &node3;
	
	printf("node1 value : %d\n", node1.value);
	printf("node2 vlaue from node1: %d\n", node1.next->value);
	printf("node3 vlaue from node1: %d\n", node1.next->next->value);
}
