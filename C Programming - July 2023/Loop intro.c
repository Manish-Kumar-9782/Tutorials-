#include<stdio.h>

/*
    1. for loop
    2. while

    syntax of for loop:

    for(initialization; condition; increment/decrement){

        // single or multiple statement
    }

    // a single cycle of process is called iteration.
*/

void main(){

    int initial = 0;
    int end = 10;
    int sum = 0;

    for(int i=initial; i<=end; i++){

        sum += i;
    }

    printf("Totoal sum: %d\n", sum);
}
