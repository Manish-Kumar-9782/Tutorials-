#include<stdio.h>

void main(){

    int a = 10;
    int b = 20;

    // single if condition
    if(a>b){
        printf("a is greater than b\n");
    }

    // double if-else condition
    // this or that type condition

    if(a>b){
        printf("a is greater than b\n");
    }
    else{
        printf("a is less than b or equal to b\n");
    }

    // multiple if else statement

    if(a>b){
        printf("a is greater than b\n");
    }
    else if(a<b){
        printf("a is less than b\n");
    }
    else{
        printf("a is equal to b\n");
    }


    printf("\n----------------END PROGRAM----------------\n");
}
