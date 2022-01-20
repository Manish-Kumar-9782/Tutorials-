// Recursion: Recursion is a process in which a function calls itself 
// if we dont provide a stop condition in the recursion calls then our porgram will run agian and again.

// in this section we will compute the factorial of a first n integers.

#include<stdio.h>cl

int factorial(int n){

    int fact=1;
    if (n==1)
        return 1;  // this is the termination condition of stopping the recursion calls.
    
    else 
        fact = n*factorial(n-1);

    return fact;
}

void main(){

    int n;
    int fact;
    printf("Enter the number: ");
    scanf("%d", &n);

    fact = factorial(n);

    printf("\nFactroal of %d:  %d", n, fact);
}


