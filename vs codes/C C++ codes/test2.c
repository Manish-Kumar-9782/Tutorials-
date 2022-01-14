#include<stdio.h>

long double  factorial(int);

int main()
{
    int n=20;
    printf("Factorial of %d: %Lf",n, factorial(n));
    return 0;
}

long double factorial(int a){

    long double result =1.0;
    for(int i=1; i<=a; i++){
        result *= i;
    }
    return result;
}