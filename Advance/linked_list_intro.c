#include<stdio.h>

typedef struct Node{
	
	int data;
	
	struct Node *next;
	
}node;

void main(){
	
//	node *root;
	
	node nd1;
	node nd2;
	node nd3; 
	
	node nds;
	
//	assigning some values to data into node
	
	nd1.data = 20;
	nd2.data = 40;
	nd3.data = 60;	
	
	
	nd1.next = &nd2;
	nd2.next = &nd3;
	
//	nds = *nd1.next;
	
	printf("value of nd1: %d\n", nd1.data);
	printf("value of nd2: %d\n", nd1.next->data);
	printf("value of nd3 : %d\n",nd2.next->data);
	
}
