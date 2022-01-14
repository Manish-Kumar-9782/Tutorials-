#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
    // 'struct node' is the data type for which we store the reference (address) value in *link pointer 
    
};

int main(){
    struct node *head = NULL;
    // making a head for the linked list to store the initial address for the initial node
    head = (struct node *)malloc(sizeof (struct node));
    // assigining thr first node value to head

    head->data = 45;
    head->link = NULL;

    printf("%d", head->data);

    return 0;  

}

