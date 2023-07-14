#include<stdio.h>

/*
    sentinal loop or non-counter controlled loop

    syntax:

        while(condition){
            // statements
            }
*/

void main(){

    int i=0;

    while(i<10){

       printf("%d. Hello world..\n",i);

       i++;
    }

    printf("\n-----------------------------------\n");

    for(int i=0; i<5; i++){

        for(int j=0; j<10; j++){
            printf("[%d,%d] ",i,j);
        }

        printf("\n");
    }

    printf("\n-----------------------------------\n");

    for(int i=0; i<5; i++){

        for(int j=0; j<=i; j++){
           printf("%d", j);
        }

        printf("\n");
    }

}
